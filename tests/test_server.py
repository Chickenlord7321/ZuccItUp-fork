import pytest
#from bson.objectid import ObjectId 
from pymongo import MongoClient
from order import Order
from server import Server
from unittest.mock import patch, MagicMock

"""Unit Tests for server.py and DB actions"""


@patch("server.MongoClient")
def test_init_success(mock_mongo):
    """Unit test to simulate the DB connection"""
    # Mock client instance
    mock_client = MagicMock()
    mock_mongo.return_value = mock_client

    # Mock database
    mock_db = MagicMock()
    mock_client.get_database.return_value = mock_db

    # Simulate successful ping
    mock_db.command.return_value = {"ok": 1}

    # Instantiate class (uses mock instead of real MongoClient)
    obj = FoodDeliveryDB("user123", "pass123")

    # Assertions
    mock_mongo.assert_called_once()  # MongoClient was called
    mock_client.get_database.assert_called_with("user123_project")
    mock_db.command.assert_called_with("ping")

    # Collections assigned correctly
    assert obj._FoodDeliveryDB__user == mock_db["user"]
    assert obj._FoodDeliveryDB__menu == mock_db["menu"]
    assert obj._FoodDeliveryDB__order == mock_db["order"]
  
