# Authors: Surya Balram

import notification     #importing member functions from notification.py
from order import Order,Cart            #importing member functions from order.py
from menu import Menu, MenuItem            #importing member functions from menu.py
from user import Customer
from notification import Notification


def customer_main(server):
   #call from main, customer portal
 
    # ── Login ──────────────────────────────────────────────────────
    print("\n" + "═" * 50)
    print("  ZuccItUp — Customer Portal")
    print("═" * 50)
    #add password
    viuid = input("Enter your VIUID: ").strip()
    temp = Customer(VIUID=viuid, name="", email="", role="Customer", server=server)
    #verify id
    if not temp.verifyVIUID():
        print("No customer account found with that VIUID. Please try again.")
        return
    #search user and check
    user_data = server.view_user(viuid)
    if not user_data or user_data.get("role") != "Customer":
        print("No customer account found with that VIUID. Please try again.")
        return
    #build Customer object from the database record
    customer = Customer(
        VIUID=user_data["VIUID"],
        name=user_data["name"],
        email=user_data["email"],
        role=user_data["role"],
        server=server,
    )
    customer.previouslyOrdered = user_data.get("previouslyOrdered", [])
    
    print(f"\nWelcome, {customer.name}!")
    #input
    building = input("Enter your building number (e.g. 315): ").strip()
    room     = input("Enter your room number (e.g. 114): ").strip()
    #initialise cart
    cart = cart(building=building , room=room , server=server)
 
    # ── Menu loop ──────────────────────────────────────────────────
    while True:
        print("\n" + "─" * 45)
        print("  What would you like to do?")
        print("─" * 45)
        print("  1. Browse all menus")
        print("  2. Search menu by type")
        print("  3. Look up a specific item")
        print("  4. Add item to cart")
        print("  5. View cart")
        print("  6. Change item quantity")
        print("  7. Remove item from cart")
        print("  8. Place order")
        print("  9. View my orders")
        print(" 10. View notifications")
        print(" 11. View my profile")
        print("  0. Logout")
        print("─" * 45)
 
        choice = input("Enter choice: ").strip()
 
        if choice == "1":
            _view_all_menus(server)
 
        elif choice == "2":
            _view_menu(server)
 
        elif choice == "3":
            _look_up_item(server)
 
        elif choice == "4":
            cart = _add_to_cart(cart, server)
 
        elif choice == "5":
            _view_cart(cart)
 
        elif choice == "6":
            cart = _change_quantity(cart)
 
        elif choice == "7":
            cart = _remove_from_cart(cart)
 
        elif choice == "8":
            cart = _place_order(customer, cart, server)
 
        elif choice == "9":
            _view_orders(customer, server)
 
        elif choice == "10":
            _view_notifications(customer, server)
 
        elif choice == "11":
            customer.viewCustomer()
 
        elif choice == "0":
            print(f"\nGoodbye, {customer.name}!")
            break
 
        else:
            print("Invalid choice. Please try again.")
 
## Notification.py
def _view_notifications(customer: Customer, server):
    #making notif class with customer name
    notif = Notification(
        heading="",
        description="",
        customer_VIUID=customer.name,
        server=server,
    )
    #calling notification.py
    notif.viewNotification()

## order.py
#place_Order
def _place_order(customer:Customer , cart:dict , server)->dict:
    #check
    if cart.num_items() == 0:
        print("\nYour cart is empty. Add some items before placing an order.")
        return False
    #calling cart in menu.py
    cart.view_cart()
    subtotal = cart.calculate_subtotal()
    print(f"\nEstimated subtotal: ${subtotal:.2f}")
 
    #choose a vendor by displaying all known menus
    menu = Menu(type="", schedule=[], publishStatus=True, server=server)
    all_menus = server.get_all_menus()
    vendor_names = sorted({m.get("vendor", "") for m in all_menus if m.get("vendor")})
    #inform of issue
    if not vendor_names:
        print("No vendors are currently available.")
        return False
    #print info
    print("\nAvailable vendors:")
    for i, v in enumerate(vendor_names, 1):
        print(f"  {i}. {v}")
 
    vendor_input = input("Choose a vendor by number: ").strip()
    #check
    if not vendor_input.isdigit() or not (1 <= int(vendor_input) <= len(vendor_names)):
        print("Invalid vendor selection.")
        return False
    vendor = vendor_names[int(vendor_input) - 1]
    
    #input instructions
    instructions = input("Special instructions (press Enter to skip): ").strip()
 
    # Confirm before placing
    building, room = cart.get_location()
    print(f"\nOrder summary:")
    print(f"  Vendor:   {vendor}")
    print(f"  Deliver:  Building {building}, Room {room}")
    print(f"  Subtotal: ${subtotal:.2f}")
    if instructions:
        print(f"  Note:     {instructions}")
 
    confirm = input("\nConfirm order? (y/n): ").strip().lower()
    if confirm != "y":
        print("Order cancelled.")
        return False
    #use the business layer: convert cart to Order, then place it
    order = cart.convert_to_orders(
        customer=customer.name,
        vendor=vendor,
        instructions=instructions,
    )
    #check
    if order is None:
        return False
    #cart_items is now cleared; gather what was in the order from the Order object
    success = order.place_order()
 
    if success:
        print(f"\nOrder placed successfully!")
        # Show the Pending notification
        notif = Notification(
            heading="",
            description="",
            customer_VIUID=customer.name,
            server=server,
            order_id=order._Order__order_id,
        )
        notif.sendNotification()
 
    return success

#viewOrders
def _view_orders(customer:Customer , server):
    #create an empty order 
    fake = Order(
        building="", room="", total=0.0,
        instructions="", customer="", vendor="",
        server=server,
    )
    #calling menu.py
    all_orders = fake.view_all_orders()
    my_orders = [o for o in all_orders if o.get("customer") == customer.name]
    #check
    if not my_orders:
        print("\nYou have no order history.")
        return
    #display
    print(f"\n{'Vendor':<22} {'Status':<15} {'Subtotal':>10}  Location")
    print("─" * 50)
    for o in my_orders:
        loc = f"Bldg {o.get('building', '?')}, Rm {o.get('room', '?')}"
        print(
            f"{o.get('vendor', ''):<22} "
            f"{o.get('orderStatus', ''):<15} "
            f"${o.get('subTotal', 0.0):>9.2f}  "
            f"{loc}"
        )

#addToCart = input
def _add_to_cart(cart:dict , server)->dict:
    #input
    name=input("\nEnter item name to add: ").strip()
    #check
    if not name:
        return
    #input quantity
    qty_input = input("Enter quantity: ").strip()
    #check
    if not qty_input.isdigit() or int(qty_input) <= 0:
        print("Please enter a valid quantity (must be 1 or more).")
        return
    #calling cart in order.py
    cart.add_to_cart(name, int(qty_input))
    return cart

#viewCart
def _view_cart(cart:dict):
    if not cart:
        print("\nYour cart is empty.")
        return
 
    print(f"\n{'Item':<25} {'Qty':>5}")
    print("─" * 35)
    for item, qty in cart.items():
        print(f"{item:<25} {qty:>5}")
    print("─" * 35)
    print(f"  {len(cart)} item type(s) in cart.")


## menu.py
#viewMenu = input
def _view_menu(server):
    print("\nAvailable types: Breakfast, Lunch, Dinner, General")
    menu_type = input("Enter menu type: ").strip()
    if not menu_type:
        print("No type entered.")
        return
    menu = Menu(type=menu_type, schedule=[], publishStatus=True, server=server)
    menu.viewMenu()

#viewAllMenus
def _view_all_menus(server):
    #call menu.py after creating menu object
    menu = Menu(type="", schedule=[], publishStatus=True, server=server)
    menu.viewAllMenus()
    
#lookUpItem
def _look_up_item(server):
    #call menu.py
    item = MenuItem(name="", price=0.0, description="", inStock=True, allergens="")
    item.server = server
    item.viewItem()
    
#changeQuantity
def _change_quantity(cart: dict) -> dict:
    #check
    if cart.num_items() == 0:
        print("\nYour cart is empty.")
        return
    
    cart.view_cart()
    #input
    name = input("\nEnter item name to update: ").strip()
    qty_input = input("Enter new quantity (0 to remove): ").strip()
    #check
    if not qty_input.isdigit():
        print("Please enter a valid number.")
        return
 
    cart.change_quantity(name, int(qty_input))

#removeFromCart
def _remove_from_cart(cart: dict) -> dict:
    #check
    if cart.num_items() == 0:
        print("\nYour cart is empty.")
        return
    #call helper function
    cart.view_cart()
    #input
    name = input("\nEnter item name to remove: ").strip()
    #calling cart in menu.py
    cart.remove_from_cart(name)

#calculateSubTotal
#def _calculate_subtotal(cart: dict, server) -> float:
    
    