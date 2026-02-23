# Team Project: Project Requirements

* Team Name: Kirby Space Program

## Document Overview

This document contains an analysis of the information we gathered from interviews with users of the system. It covers use cases describing the functionality of the system, functional and non-functional requirements, a set of features to be developed for the demo, and a plan for engaging with clients throughout development.

### Table of Contents

1. [Updates](#updates)

	1. [Project Plan Updates](#project-plan-updates)

	2. [Risk Plan Updates](#risk-plan-updates)

		1. [List of Risks](#list-of-risks)

		2. [Organizational](#organizational)

		3. [Technological](#technological)

		4. [Resource](#resource)

		5. [Risk Plan](#risk-plan)

2. [Data Collection](#data-collection)

	1. [Background Research](#background-research)

	2. [Interviews](#interviews)

		1. [Identifying and Recruiting Users](#identifying-and-recruiting-users)

		2. [Interview Process](#interview-process)

		3. [Interview Data](#interview-data)

		4. [Vendor](#vendor)

		5. [Customers](#customers)

		6. [Summary of Interview Insights](#summary-of-interview-insights)

3. [Users](#users)

4. [Use Cases](#use-cases)

	1. [Use Case Diagrams](#use-case-diagrams)

5. [Product Requirements](#product-requirements)

	1. [Product Summary](#product-summary)

	2. [Requirements](#requirements)

		1. [Functional Requirements](#functional-requirements)

		2. [Non-Functional Requirements](#non-functional-requirements)

	3. [Feature Set](#feature-set)

		1. [Essential Features](#essential-features)

		2. [Stretch Features](#stretch-features)

6. [User Engagement Plan](#user-engagement-plan)

## Updates  

### Project Plan Updates

* Removed payment processing as a feature of the system. This was removed since this is not a feature in the scope of this project and would be handled by third party software.

* Modified problem statement to clarify product description and intentions. Previously there was some ambiguity on the scope of vendors and how it positively affects users. Also clarified the limitations of other delivery systems in comparison to the proposed system. 

Updated Problem Statement:
**Problem:** The problem we aim to solve is the lack of a simple and efficient way for people at VIU to get food delivered across campus. Students, faculty and staff often have short breaks between classes or work and may not have enough time to walk to food outlets, wait in line, and return to their building — leading to skipped meals and rushed schedules. 

This project addresses this gap by providing a peer-based delivery system that organizes food orders, delivery locations, and menus in one place, making on-campus food access more convenient and efficient. This system will provide delivery from any on-campus food vendor to any building on campus. Current delivery methods to the VIU campus are limited to the student housing, while this campus-specific app will allow customers to have food delivered to any building on campus. Along with the boost in food availability there will be a boost to VIU’s local economy, as VIU vendors will see increased income, and students who sign up to become delivery agents will be provided with jobs (peer-based delivery).

### Risk Plan Updates

We have reduced our lists of risks to just 5, as required by A2, as well as added labels to better align with table 1\. Also, in the previous assignment, we were confused about how the “threshold-frequency-who” structure applied to our chosen risks, so we went with a more detailed description of what we could do to mitigate them. This has been updated to follow the “threshold-frequency-who” structure, and we’ve added a comments column for our more detailed breakdowns of the risks.

### List of Risks

#### Organizational

* **Vendor Non-Cooperation:** Cafeteria and Subway may not want to be part of this system.

* **Disruption of Regular Work:** Must follow VIU/Professor policies \- don’t disrupt class.

* **Staff Overhead:** staff have to package each meal and place it in a kiosk.

#### Technological

* **Database Implementation:** Oracle runs on an old server with outdated versions of GCC and C++ and will be difficult to use. However, Oracle is the only DBMS we have that at least 2 people are familiar with.

#### Resource

* **Theft:** Agents or other people may steal and/or eat the food

### Risk Plan

|  | Risk Name | Risk Description | How to monitor | Plan | Comments |
| :---- | :---- | :---- | :---- | :---- | :---- |
| 1 | Vendor Non-Cooperation | The cafeterias, Subway, and food stands may not want to be part of this system. | **Threshold:** vendors must be willing to try out our system. **Frequency:** interview vendor staff at least twice during the project. **Who:** any team member. | Mitigate | We will interview vendors throughout development to get feedback on which features they would like/dislike. This will also help vendors become more familiar with the system. |
| 2 | Disruption of Regular Work | Delivery cannot be done to places where food is not allowed and during tests or presentations. | **Threshold:** faculty can report policy violations. **Frequency:** reports are reviewed weekly. **Who:** system admins. | Mitigate | Delivery agent policy states that they are not allowed to enter classrooms while class is in session. However, if a violation occurs, the customer or faculty can lodge a complaint allowing admin to take action. |
| 3 | Staff Overhead | Staff will have to package every meal and leave it out for pickup. This adds additional overhead to their workload. | **Threshold:** vendor staff or delivery agents can report issues with the pickup process. **Frequency:** reports are reviewed weekly. **Who:** system admin. | Share/Deal with it | While we cannot fully reduce the overhead, drivers will package self-serve items (e.g. coffee) themselves. However, vendors will be compensated with increased business and thus more revenue, allowing them to afford better equipment and  more staff. |
| 4 | Database Implementation | Oracle is difficult to work with on the Otter server, as it is very old and runs primitive versions of GCC and C++. However, we lack experience with other DBMS. | **Threshold:** DBMS must support our core features and ideally a web interface. **Frequency:** tests and demos must be conducted before A3 is due. **Who:** all team members. | Mitigate or Deal with it  | We will create demos before development begins to test other DBMS. If another system runs on the lab machines and allows us to create a front end easier, we will use it instead. We will also speak to Merlin to help us set up another DBMS if need be. Otherwise, we will just have to use Oracle and limit the scope of the project. |
| 5 | Theft | Theft by Delivery Agents who take the food and eat it themselves or people posing as Agents to steal the food. | **Threshold:** customers or delivery agents can report theft. **Frequency:** reports are reviewed weekly. **Who:** system admin. | Share/Mitigate | Theft by Delivery agents will be dealt with by customers giving feedback about the agent. People posing as agents will not be able to pick up orders since there will be a OTP (One time Passcode) given to both the Vendor and Agent who must corroborate the code before exchanging the package. |

#### Table 1: Risk Plan Table

## Data Collection

### Background Research

Doordash: [Doordash link](https://www.doordash.com/en-CA/?ignore_splash_experience=true&&utm_source=Google&utm_medium=SEMb&utm_campaign=CX_CA_SE_SB_GO_ACQ_24XXXX_2038387838_RSTRNT_+BR_ACQ_INMKT_GENDELIVERYXX_EVG_CPAX_EPX_COCAN_EN_EN_X_DOOR_GO_SE_TXT_XXXXXXXXXX&utm_term=doordash&utm_content=73780474922&kclickid=_k_CjwKCAiAs4HMBhBJEiwACrfNZTBMitQduDmN8z8Bdit9rj1goRggidNwjRPyGX2h_zbzEQ6zNDZXxhoCWDIQAvD_BwE_k_&utm_adgroup_id=73780474922&utm_creative_id=562542935945&utm_keyword_id=kwd-63454401416)

They allow you to change the delivery location, it is not restricted to your home address. They provided delivery from stores and restaurants of all kinds. Vendors featured on Doordash have developed safe bagging systems using stickers/staples and codes associating drivers with orders to make sure that food is untampered and going to the correct client. In order to maintain the quality and temperature of the food, drivers are given insulated bags to keep food warm and dry. The app also provides the customer with a live map displaying the drivers location in relation to the vendor and the delivery address, while also providing a time estimation to completed delivery. 

Our system will differ from selection, we will limit the selection to on campus food vendors and delivery locations. This will keep all economic benefits within the university and significantly decrease the delivery time given the proximity. The proximity of vendors to customers should allow minimal fees to the users compared to Doordash where fees can reach $6. We will associate delivery agents with orders based on the student number of the driver and use similar bagging techniques to ensure safe food delivery. 

### Interviews

Understanding the needs of the users of the system is critical to designing a product that effectively supports real-world workflows and constraints. To accomplish this, the team conducted interviews with representative users of the proposed system. These interviews allowed the team to validate assumptions, uncover operational concerns, and better understand the daily challenges faced by on-campus food vendors and students. Engaging directly with users helped build trust, encouraged honest feedback, and ensured that system requirements were grounded in actual user needs rather than assumptions.

#### Identifying and Recruiting Users

Users were identified and recruited based on their relevance to the system and their ability to represent different user groups within the on-campus food delivery system. Participants were recruited informally through in-person conversations on the VIU campus.

The team engaged users from the following user groups:

* Vendors, represented by an on-campus food vendor with direct experience preparing and serving food to customers.  
* Customers, represented by a student who frequently purchases food on campus and experiences time constraints between classes.

These users were selected because they cover a breadth of needs and bring domain knowledge that the development team lacks, such as vendor workflow constraints, peak service times, and student food-access challenges. Both participants were recruited on the VIU campus while participating in related activities. Both participants also indicated willingness to provide further feedback throughout the term.

#### Interview Process

All interviews were conducted using a standardized interview script to ensure consistency and professionalism. Interviews were conducted while interviewers were physically present on campus, although the mode of communication differed depending on participant availability.

Each interview included:

* An introduction identifying the interviewer, note taker and the course project.  
* A sincere expression of gratitude for the participant’s time.  
* A clear statement of intent describing:  
  * The purpose of the interview.  
  * How interview data would be anonymized and used solely for academic purposes.  
* A set of open-ended questions designed to encourage discussion and insight.  
* Space for real-time note-taking.  
* An opportunity for the interviewee to ask questions.  
* A closing thank-you.

The vendor interview was conducted by phone, while the customer interview was conducted in person. In both cases, notes were taken in real time by a designated note taker. The interviews revealed important insights into vendor concerns such as order pickup reliability, and delivery timing, as well as customer needs related to affordability, trust in delivery agents, and flexible delivery options. These findings directly informed the system’s use cases, functional requirements, and feature prioritization.

|  | Interviewee ID | User Type | Interviewer | Date/Time |
| :---- | :---- | :---- | :---- | :---- |
| 1\. | Vendor1 | Vendor | Surya | 02/01/26 @2:00PM |
| 2\. | Customer1 | Customer | Surya | 02/03/26 @10:10AM |
| 3\. |  |  |  |  |
| 4\. |  |  |  |  |

### Interview Data

The interviews provided insight into how different users interact with on-campus food services, the challenges they face, and how a peer-based delivery system could address those challenges. While there was some overlap in needs between user types, clear differences emerged in goals, benefits, and tasks, reinforcing the distinction between vendors and customers.

### Vendor

#### Primary Goal

The vendor’s primary goal is to efficiently prepare and distribute food to customers while minimizing disruption to existing workflows and avoiding unnecessary overhead.

#### How the Vendor Benefits from the System

The vendor benefits from increased visibility across campus and access to customers who may not be able to physically reach the food stand during peak hours. The system also provides a structured method for associating orders with delivery agents, reducing confusion during pickup and improving order accuracy.

#### Primary Vendor Tasks

1. Update and manage the menu, including weekly featured items.  
2. Accept or decline incoming orders based on capacity and availability.  
3. Package completed orders and hand them off to delivery agents using a clear order identification method (e.g., order codes).

### Customers

#### Primary Goal

The customer’s primary goal is to access food conveniently during short breaks between classes without needing to travel across campus or skip meals.

#### How the Customers Benefits from the System

The customer benefits from time savings, improved access to food during busy schedules, and the ability to receive meals in locations that are otherwise inconvenient to leave. The system also provides reassurance through delivery transparency, such as agent verification and delivery confirmation.

#### Primary Vendor Tasks

1. Browse available menus and place food orders.  
2. Select a delivery location or pickup method that fits class constraints.  
3. Receive delivery notifications and confirm receipt of the order.

### Summary of Interview Insights

The interview process highlighted the importance of aligning system design with real operational constraints rather than assumptions. Vendors were less concerned with technological complexity and more focused on reliability, clear order identification, and minimizing disruptions to their workflow. Customers emphasized affordability, trust in delivery agents, and flexible delivery options that fit academic schedules. The interviews differed from initial expectations in that vendors did not view delivery as a burden, but rather as a potential benefit if implemented carefully. Overall, direct user engagement clarified priorities and ensured that system requirements were grounded in actual user needs rather than speculative design choices.

## Users

Our system has 3 user types: customers, agents (delivery persons) and vendors. Our main user types are agents and vendors since they perform the most actions with the system. 

* Customers are users who place and receive orders.   
* Vendors are responsible for actions like updating menus, packing orders and placing them inside the kiosk.   
* Agents are responsible for accepting orders, delivering orders, confirming order status, and setting their own availability. 

## Use Cases

| Use Case | Description | User(s) associated with it |
| :---- | :---- | :---- |
| Remove from menu | Vendor removes item from the menu for customers to see | Vendor |
| Add to menu | Vendor adds a new item to the menu | Vendor |
| Update menu | Vendor updates details of menu (item details) | Vendor |
| View order | Vendor can check on pending orders | Vendor |
| Bagging order | Vendor packages the order, places it in the delivery kiosk, and marks it as ready for pickup | Vendor |
| Decline order | Vendor declines an order and gives a reason | Vendor |
| Deliver order | Agent delivers the order to the customer and uploads a picture as proof of delivery | Agents |
| Pick up order | Agent picks up the order and updates its status to “delivery in progress” | Agents |
| Make themselves available | Agent clocks in and marks themselves as available for deliveries | Agents |
| Accept Order | Agent accepts or rejects a pending order  | Agents |
| Mark order as completed | Agent marks the order as completed | Agents |
| Notify customer | Agent/system notifies the customer of delivery | Agents |
| Browse Menu | Customer browses the menu and selects a food item | Customer |
| Order Food | Customer places an order and waits for confirmation that it was accepted | Customer |
| Receive Order | Customer receives the food from the delivery agent or dropoff location | Customer |
| Receive Notification | Customer receives a notification that the order has been delivered | Customer |
| View Notification | Customer can view all notifications related to order | Customer |

#### Table 3: Use Cases

### Use Case Diagrams



#### Figure 1: Vendor Use Case Diagram

![vendor](img/Vendor_Use_Case_Diagram.jpg)

#### Figure 2: Delivery Agent Use Case Diagram

![Agent](img/Agent_use_case_diagram.jpg)

#### Figure 3: Customer Use Case Diagram

![Customer](img/Customer_Use_Case_Diagram.jpg)

#### Figure 4: All User Types Use Case Diagram

![all users](img/Use_case_diagram.jpg)

## Product Requirements

### Product Summary

The problem we aim to solve is the lack of a simple and efficient way for people at VIU to get food delivered across campus. Students, faculty and staff often have short breaks between classes or work and may not have enough time to walk to food outlets, wait in line, and return to their building — leading to skipped meals and rushed schedules. 

Our Users are hungry people, that have little to no time, This is our main customer.  
Delivery agents are people with free time that want to make a quick buck.  
Vendors are simply the people on campus that want to boost sales through delivery and advertisement.

The requirements below include the interface usage, it will ideally be accessible on a phone or tablet for all users to make it seamless.

### Requirements

#### Functional Requirements

The system must allow:

* Customers to place an order,  
* Vendors to add items to the menu,  
* Vendors to update items on the menu,  
* Vendors to remove items from the menu,  
* Vendors to accept or decline orders,  
* Agents to accept or decline orders,  
* Agents to mark orders as picked up,  
* Agents to mark orders as delivered,  
* Agents to mark themselves as available for delivery.

#### Non-Functional Requirements

* **Usability \-** the system should have a different UI for each type of user. Each user has different requirements, so they will need different interfaces.  
* **Reliability \-** the system must alert customers when their orders could not be completed and provide an explanation.  
* **Reliability \-** the system must make live updates to the menu when a menu item is out of stock.  
* **Performance \-** the system must wait a minimum of 5 minutes for an agent to accept an order before it is automatically declined.  
* **Security \-** the system must encrypt login information before storage.  
* **Security \-** the system must disclose the purpose of all personal information or access permissions collected by the system.

## Feature Set

The Essential Features we have set are made to be barebones such that the product works. The bells and whistles come with the stretch features that may or may not be completed within the timeframe of the course.

### Essential Features

| Priority | Essential Feature | Reason for priority |
| :---- | :---- | :---- |
| 1 | Vendors can add, update, or remove items from the menu | Menu must be up to date for an order to be made at all |
| 2 | Customers can view the menu and place an order for something on the menu | Without an order, there’s no delivery |
| 3 | Vendors can reject orders that they can’t complete, and accept ones they can complete | Vendors must accept and prepare the order before it can be delivered |
| 4 | Agents can get delivery requests recommended to them by changing their status to “available” | Agents must be available for deliveries before they can accept one |
| 5 | Agents can accept deliveries they want to take, and reject ones they don’t think are worth it | Agents must accept a delivery request before they can update the delivery’s status |
| 6 | Agents can update the status of their deliveries, such as “accepted”, “picked up”, or “delivered” | Once all the above steps are done, the agent can complete the order |

#### Table 4: Essential Features

### Stretch Features

| Priority | Stretch Feature | Reason for priority |
| :---- | :---- | :---- |
| 1 | Simple web interfaces for each user type (Vendor, Delivery Agent, Customer). | An interface would make our system more user-friendly, and it wouldn’t be too difficult to make a simple UI. |
| 2 | Timing system for measuring delivery times. This would allow the system to automatically decline orders that no agent accepted, as well as track the agent performance to make sure deliveries are not running late. | A timing system would improve the quality of service for customers, ensuring that food does not go cold and deliveries are not late. However, this system might be complicated to implement. |
| 3 | Live updates to the menu that display changes as users are browsing the menu. | It’s unlikely that customers will frequently have their order interrupted or cancelled due to a menu change, but it would be annoying for customers in the rare cases where it happens. |

#### Table 5: Stretch Features

## User Engagement Plan

| Model | User ID | Date | Team member | Mode (online/in-person) |
| :---- | :---- | :---- | :---- | :---- |
| Use Case Diagrams | Vendor1 | TBD, latest date by Feb 16th | Keenan | In-person |
| Use Cases | Vendor1 | TBD, latest date by Feb 16th | Surya | In-person |
| Domain Class Diagrams | Customer1 | TBD, latest date by Feb 20th | Bruce | In-person |
| ER Diagram | Customer1 | TBD, latest date by Mar 6th | Caleb | In-person |

#### Table 6: User Engagement Plan
