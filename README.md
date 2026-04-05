# Zucc It Up
The Kirby Space Program's project for CSCI 375. Zucc It Up is a food delivery system for the VIU campus.

The problem we aim to solve is the lack of a simple and efficient way for people at VIU to get food delivered across campus. Students, faculty and staff often have short breaks between classes or work and may not have enough time to walk to food outlets, wait in line, and return to their building — leading to skipped meals and rushed schedules.

## Cloning The Repo

1. Navigate to a suitable directory of your choice, such as `cd CSCI_375`.

2. Run the following two commands:
```
git clone csci:csci375/Team1/Project
cd Project
```

## Setting Up The Python Virtual Environment

The program must be run from inside a [Python virtual environment](https://www.w3schools.com/python/python_virtualenv.asp).

To create a virtual environment, you will need the following dependencies installed (these are already installed on the lab machines):
- python3 version 3.8 or later
- pip

If these are already installed, navigate to the project directory ZuccItUp/, then follow these steps:

#### 1. Create Virtual Environment

```
python3 -m venv ./venv
```

#### 2. Activate the Environment

```
source ./venv/bin/activate
```

After this, you should be able to see that you are working in the virtual environment because your command line will look something like this:

```
(venv) ...$
```

#### 3. Install All Required Packages

```
pip install -r requirements.txt
```

You are now able to run _pymango_!

### Important Reminder:

To run any Python file, you must run it from inside the virtual environment. Steps 1 and 3 are only necessary to _set up_ the environment, so they only need to be run once and never again. However, you will need to follow [step 2](#2-activate-the-environment) each time before you attempt to run a Python file.

## Setting Up The Database

1. Navigate to the DatabaseSetup directory with:
   ```
   cd DatabaseSetup/
   ```

2. Run the following to apply a schema validation to the three collections in the database (user, menu, and order):
   ```
   python3 DB_validation.py
   ```

3. For step 3, you have two options: initialize all the collections, or initialize only one collection at a time.
   1. **To initialize all the collections at once**, run ```python3 DB_init.py``` and follow the prompts to enter your MangoDB username and password.
   2. **Initialize only one collection at a time**, run ```python3 DB_<collection>.py```, where _\<collection\>_ is the name of one of the three collections (user, menu, or order).

The database is now filled with data!

## Running The Program

Navigate back up to the project root directory with:
```
cd ../
```

Now, `main.py` contains the main loop of the program. Simply run this command to begin the program!

```
python3 src/main.py
```

## What Can Zucc It Up Do?

### Enter MangoDB Credentials

First, to access the MangoDB database, you will be prompted to enter your MangoDB credentials. If you are Prof. Sarah, these will be sent to your VIU email address. If you are anyone else, we _might_ be convinced to send you our credentials if you pay us in hot dogs.

### Login or Signup

Next, you can either login to an already existing user account, or create a new account. Follow the program's prompts to do this.

Note:
- You can type "logout" at any time to log out of your Zucc It Up account.
- You can also type "quit" at any time to exit the program entirely.

### Customers:

If you are a Customer, the following features are available to you:
1. Place an order
2. View your orders
3. Confirm order received
4. View notifications
5. View your profile

Follow the prompts to complete each of these actions.

### Delivery Agents:

If you are a Delivery Agent, the following features are available to you:
1. Order a meal
2. View your active orders
3. Set your availability
4. View available deliveries
5. View your profile
6. View notifications

Follow the prompts to complete each of these actions.