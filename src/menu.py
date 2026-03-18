from collections import defaultdict
from DB_init import db


class Menu():
    def __init__(self, type: str, schedule: list, publishStatus: bool):

        self.type = type
        self.schedule = schedule
        self.publishStatus = publishStatus

    def __viewMenu(self):
        keyword = input("Search keyword (leave blank for all): ").strip()
 
        pipeline = [
            {"$match": {"type": self.type}},
            {"$unwind": "$menuItem"},
        ]
        if keyword:
            pipeline.append(
                {"$match": {"menuItem.name": {"$regex": keyword, "$options": "i"}}}
            )
        pipeline.append({"$project": {
            "name": "$menuItem.name",
            "price": "$menuItem.price",
            "description": "$menuItem.description",
            "inStock": "$menuItem.inStock",
            "allergens": "$menuItem.allergens",
        }})
 
        items = list(db.menu.aggregate(pipeline))
        if not items:
            print("No items found.")
            return
 
        print(f"\n{'#':<4} {'Name':<25} {'Price':>8}  {'In Stock':<10}  Description")
        print("─" * 75)
        for i, item in enumerate(items, 1):
            stock = "Yes" if item.get("inStock") else "No"
            print(
                f"{i:<4} {item.get('name', ''):<25} "
                f"${item.get('price', 0):>7.2f}  "
                f"{stock:<10}  "
                f"{item.get('description', '')}"
            )
 
    def viewAllMenus(self):

        pass

class MenuItem():
    def __init__(self, name: str, price: float, description: str, inStock: bool, allergens: str):

        self.name = name
        self.price = price
        self.description = description
        self.inStock = inStock
        self.allergens = allergens

    def addToCart(self):
        pass

    def viewItem(self): 
        pass

    def viewAllItems(self):
        # pseudocode needs database implementation
        orders = list(db.orders.find()) # list of orders from db
        if not orders:
            print("You have no orders yet.")
            return
        for order in orders: 
            print("__" * 25)
            print("") #the actual order
            print("__" * 25)