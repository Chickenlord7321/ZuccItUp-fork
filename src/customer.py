# Authors: Surya Balram

import notification     #importing member functions from notification.py
import order            #importing member functions from order.py
import menu             #importing member functions from menu.py

## Notification.py
#viewNotification



## order.py
#place_Order
def customer_place_order(self):
    bool message = place_Order(self)    #calls place_order function from order.py and stores in message variable

#viewOrder
def customer_view_order(self):
    dict message = viewOrder(self)      #calls view_order function from order.py and stores in message variable

#seeAllTimes / TBD

#addToCart = input
def customer_add_to_cart(self):
    menu_item = input("Enter the menu item you want to add to your cart: ").strip()     #asks user to input the menu item, and stores in menu_Item variable
    quantity = input("Enter the quantity: ").strip()    #asks user to input the quantity, and stores in quantity variable
    add_to_cart(self, menu_item, quantity)              #passes menu_item and quantity to add_to_cart function from order.py

#viewCart
def customer_view_cart(self):
    dict message = view_cart(self)      #calls view_cart function from order.py and stores in message variable

#enterLocation = input / TBD



## menu.py
#viewMenu = input
def customer_view_menu(self):
    keyword = input("Search keyword (leave blank for all): ").strip()   #asks user to input a search keyword, and stores in keyword variable
    view_menu(self, keyword)            #passes keyword to view_menu function from menu.py

#viewAllMenus
def customer_view_all_menus(self):
    message = view_all_menus(self)      #calls view_all_menus function from menu.py and stores in message variable