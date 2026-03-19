from pymongo import MongoClient as MangoClient	# will this work?
import getpass

name = input("Enter mongoDB username \n")

password = getpass.getpass("Enter your Mango password:\n> ")
uri = f"mongodb://" + name + ":{password}@studb-mongo.csci.viu.ca:27017/" + name + "_project?authSource=admin"
client = MangoClient(uri)

db = client.get_database(name + "_project")
user = db.get_collection("user")

# Vendors
lower_caf = {
	"name": "Lower Cafeteria",
	"email": "foodservices@viu.ca",
	"VIUID": "000000001",
	"role": "Vendor",
	"location": "Building 185 Cafeteria",
	"hoursOfOperation": {
		"days": "Mon-Fri",
        "startTime": "07:30",
        "endTime": "14:00",
	}
}

upper_caf = {
	"name": "Upper Cafeteria",
	"email": "foodservices@viu.ca",
	"VIUID": "000000002",
	"role": "Vendor",
	"location": "Building 300 Cafeteria",
	"hoursOfOperation": {
		"days": "Mon-Fri",
        "startTime": "07:30",
        "endTime": "19:00",
	}
}

unleashed_hot_dogs = {
	"name": "Unleashed Hot Dogs",
	"email": "unleashedhotdogs@gmail.com",	# made-up email 'cos the hot dog guy doesn't have one (that I can find)
	"VIUID": "000000003",
	"role": "Vendor",
	"location": "Royal Bank Plaza",
	"hoursOfOperation": {
		"days": "Tue-Thu",
        "startTime": "11:00",
        "endTime": "15:00",
	}
}

user.insert_many([lower_caf, upper_caf, unleashed_hot_dogs])

# Customers
dr_sarah = {
	"name": "Dr. Sarah Elizabeth Carruthers",
	"email": "sarah.carruthers@iu.ca",
	"VIUID": "100000000",
	"role": "Customer",
	"previouslyOrdered": [],
}

keenan = {
	"name": "Caleb Bronn",
	"email": "brick.cuppy@gmail.com",
	"VIUID": "633377721",
	"role": "Customer",
	"previouslyOrdered": [],
}

caleb = {
	"name": "Keenan Wolfe",
	"email": "Paniniwolfe@gmail.com",
	"VIUID": "666742069",
	"role": "Customer",
	"previouslyOrdered": [],
}

user.insert_many([dr_sarah, keenan, caleb])

# Delivery Agents
bruce = {
	"name": "Bruce Fernandes",
	"email": "Bruixisawesome@gmail.com",
	"VIUID": "777888999",
	"role": "Customer",
	"availabilityStatus": True,
}

surya = {
	"name": "Surya Balram",
	"email": "suryasgotgame@hotmail.com",
	"VIUID": "123123123",
	"role": "Customer",
	"availabilityStatus": True,
}

user.insert_many([bruce, surya])