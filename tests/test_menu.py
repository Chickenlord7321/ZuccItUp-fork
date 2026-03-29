from src.menu import Menu
#from menu import MenuItem
from unittest.mock import MagicMock, patch

"""Unit Tests for menu.py"""

def test_view_menu(mock_db):

    fake_server = MagicMock()

    #This is the test data that the function will be run on
    fake_server.search_menu_items.return_value = [
        {
            "name": "Coffee",
            "price": 2.50,
            "description": "Fresh Brewed coffee",
            "inStock": True,
            "allergens": "none"
        }
    ]

    menu = Menu(
        #db=mock_db,
        schedule=["Monday-Friday: 7:30am - 9:30am"],
        server=fake_server
     )

    menu.type = "Breakfast"
    

    with patch("builtins.input",return_value="Coffee"):
        with patch("builtins.print") as mock_print:
            menu.viewMenu() #Function to be tested

    fake_server.search_menu_items.assert_called_with(
        menu_type="Breakfast",
        keyword="Coffee"
    )

    assert mock_print.call_count > 0
