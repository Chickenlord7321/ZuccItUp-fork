# Team Project: Project Plan

Team Name: Kirby Space Program

Members:

* Bruce  
* Caleb  
* Keenan  
* Surya

## Document Overview

This document contains our project proposal and a management plan for tracking tasks, analyzing risks, and mitigating them wherever we can. It also lists our planned procedures for version control, development, and writing documentation, as well as a brief summary of our code and documentation standards.

### Table of Contents

1. [Updates to A1](#updates-to-a1)  
2. [Project Proposal](#project-proposal)  
   1. [Preliminary Prioritized Features](#preliminary-prioritized-features)  
3. [Management Plan](#management-plan)  
   1. [Task Tracking](#task-tracking)  
   2. [Technical Processes](#technical-processes)  
4. [Risk Analysis](#risk-analysis)  
   1. [List of Risks](#list-of-risks)  
   2. [Risk Plan](#risk-plan)  
   3. [Risk Management Framework](#risk-management-framework)

## Updates to A1

* Removed the physical abuse section of consequences.  
* Added git control rules to policies.   
* Made changes to our problem statement.  
* Fixed an error in the Roles and Technology document. We had accidentally swapped around Surya’s primary and secondary roles.  
* Modified the AI use reporting policies to be less strict.  
* Addressed the issues with our attendance policy.

## Project Proposal

**Project name:** Zucc It Up

**Project overview:** Zucc It Up is a VIU Campus Delivery system that lets students, staff, and faculty place food orders from on-campus sellers and request delivery to any campus building.

**Problem:** The problem we aim to solve is the lack of a simple and efficient way for people at VIU to get food delivered across campus. Students, faculty and staff often have short breaks between classes or work and may not have enough time to walk to food outlets, wait in line, and return to their building — leading to skipped meals and rushed schedules. There is no system that allows VIU community members to coordinate peer-based food delivery on campus. This project addresses this gap by providing a structured, database driven system that organizes food orders, delivery locations, and delivery users in one place, making on-campus food access more convenient and efficient.

### Preliminary Prioritized Features

#### Core Features

1. **Customers Place Orders:** Customers can place orders by selecting a vendor, menu items, quantities, and a delivery building. All order details are stored in the database.

2. **Pickup by Delivery Agents:** Delivery Agents can view available orders, accept them, and update the customer on their order’s status. Then Agents can pick up the order from the pickup kiosk.

3. **Menu Management for Vendors:** Vendors (cafeteria staff, Subway staff, food stand staff, etc.) can add, update, or remove menu options so customers can see the latest menus.

4. **One-Time Passcode:** Each order is assigned a unique one-time passcode (OTP) that vendor staff must verify before releasing food, ensuring correct and authorized pickup.

5. **Payment Processing System:** Payment must be verified with a credit card number and CVV. The credit card number may be stored (encrypted) for payment processing, but the CVV will not be stored.

6. **Order History and Record Keeping:** The system stores completed orders for reference, reporting, and accountability.

#### Stretch Goals

1. **Reporting System:** Allows customers, delivery personnel, or staff to report issues such as misuse, missing orders, or inappropriate behaviour for review.

2. **Secure Packaging:** Use of paper bags with seal safety stickers to ensure food orders are not opened or altered during delivery.

3. **Secure Cafeteria Kiosks:** lockable kiosks at the cafeteria where completed orders are stored and unlocked using the unique security code for secure and contactless pickup.

4. **Student ID Integration for Building Access:** Delivery personnel can associate their student ID with an order to indicate authorized access to campus buildings during delivery.

## Management Plan 

### Task Tracking 

We are using [Kanbanflow.com](http://Kanbanflow.com) for this project to track our tasks. Core module (A1-A6) documents will be named and tagged with their module like “Requirements Document A3“ and each module will have its own color. The main documents will have a subtask for each part of the document, each one of these subtasks will get their own task/box on the board and then be assigned to a team member. Each task will be given a due date that aligns with the due date of the module. At the start of the module all module tasks will be put in the “Current module” table, as team members start tasks they will move them to the “In progress” table, and once complete the task is moved to the “Done” table. Once all subtasks are completed the main module task can also be moved to the “Done” table. 

### Technical Processes 

We will have two primary branches on our GitHub repository:

* *main*: the default branch for development.  
* *release*: the branch where the current release version is kept.

Each team member will have their own fork of the main repo for working on their individual sections of the project. To merge new updates, files, or directories to *main*, members must make a pull request. Pull requests can be reviewed by any member of the team, but should be pushed by the designated Version Control Managers (i.e. the Github Grubs). 

The Pull Request Review Process follows as so:

1. Any team member can review a pull request on the project repo’s Github page.  
2. They review whether:  
   1. The code compiles;  
   2. There are no spelling/grammar errors in the documentation;  
   3. All policies and standards are followed;  
   4. The code passes all tests, if there are any.  
3. The team member makes a comment if there are any issues or concerns.  
   1. If an issue exists, the pull request will not be accepted until they are addressed.  
4. Finally, a Github Grub accepts the pull request and merges it to *main*.

We will also make use of Github Tags to keep track of each version of the project as we proceed through the semester. This will help us to track our progress on Github and revert to an older version if at the utmost end of need.

For more info, our code, documentation, and version control standards can be found in the Team Contract document.

## Risk Analysis 

### List of Risks 

#### Organizational

* Liability for injuries to delivery agents.
* Students may use this to annoy agents by placing an order and then cancelling it as soon as it is delivered.
* Cafeteria and Subway may not want to be part of this system.
* Must follow VIU/Professor policies \- don’t disrupt class.
* Agents/users might be skeptical of using the system.
* Additional overhead for cafeteria staff \- they have to package each meal and place it in a kiosk.

#### Technological

* Our (lack of) skills, particularly in databases. 
* Oracle runs on an old server with outdated version of GCC and C++ and will be difficult to use. However, Oracle is the only DBMS we have that at least 2 people are familiar with.
* Updating menus. Cafeteria staff need to update it regularly (Have a tablet where they can do it easily and have hourly/regular Reminders to update Menu)  
* Security of online payments

#### Resource

* Bags need to be recyclable
* Agents may eat the food
* Other people may steal the food.
* Agents need to have student ID cards to get into certain buildings, or else they have to leave the food at the door.
* We need to add a kiosk to each cafeteria (Optional)

#### Schedule

* Sep-Apr will be the busiest season, rest of the year will be dead

### Risk Plan

|  | Risk Name | Risk Description | How to monitor | Plan |
| :---- | :---- | :---- | :---- | :---- |
| 1 | Vendor Non-Cooperation | The cafeterias, Subway, and food stands may not want to be part of this system. | We will interview vendors throughout development to get feedback on which features they would like/dislike. This will also help vendors become more familiar with the system. | Mitigate |
| 2 | Disruption of Regular Work | Delivery cannot be done to places where food is not allowed and during tests or presentations. | Delivery agent policy states that they are not allowed to enter classrooms while class is in session. However, if a violation occurs, the customer or faculty can lodge a complaint allowing admin to take action. | Mitigate |
| 3 | Staff Overhead | Staff will have to package every meal and leave it out for pickup. This adds additional overhead to their workload. | Agents will take pictures of the package before pickup and upon dropoff, this will allow the system to hold people accountable for packaging meals properly. | Share |
| 4 | Database Implementation | Oracle is difficult to work with on the Otter server, as it is very old and runs primitive versions of GCC and C++. However, we lack experience with other DBMS. | We will create demos before development begins to test other DBMS. If another system runs on the lab machines and allows us to create a front end easier, we will use it instead. We will also speak to Merlin to help us set up another DBMS if need be. Otherwise, we will just have to use Oracle and limit the scope of the project. | Mitigate or Deal with it |
| 5 | Payment Security | Figuring out Securing Payment Details online is going to be a challenge. | To secure payment details we will have to run extensive tests to see that we do not expose the details at any point. Users will also be able to report leaked payment details. | Mitigate |
| 6 | Theft | Theft by Delivery Agents who take the food and eat it themselves or people posing as Agents to steal the food. | Theft by Delivery agents will be dealt with by customers giving feedback about the agent. People posing as agents will not be able to pick up orders since there will be a OTP (One time Passcode) given to both the Vendor and Agent who must corroborate the code before exchanging the package. | Share/Mitigate |

#### Table 1: Risk Plan Table

### Risk Management Framework

|  | Low Impact | Med Impact | High Impact | Critical Impact |
| :---- | :---- | :---- | :---- | :---- |
| Low Risk |  |  | Payment Security |  |
| Med Risk |  | Staff Overhead | Theft | Vendor Non-Cooperation |
| High Risk | Disruption of Regular Work |  |  |  |
| Critical Risk |  | Database Implementation |  |  |

#### Table 2: Risk Management Framework
