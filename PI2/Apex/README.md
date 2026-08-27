# Gym Management System Web Template

A comprehensive and responsive gym management administration system built with **HTML5, CSS3, and Vanilla JavaScript**.

This project provides a complete front-end solution for managing gym members, membership plans, subscriptions, payments, trainers, classes, class bookings, check-ins, schedules, expenses, analytics, and reports.

It is designed as a downloadable web template that can run locally without React, Next.js, a backend, database, or account system.

## Features

### Dashboard

Get a complete overview of gym operations.

- Total Members
- Active Memberships
- Expiring Memberships
- Expired Memberships
- Monthly Revenue
- Outstanding Payments
- Today's Check-Ins
- Active Classes
- Trainers
- Member Growth
- Revenue Trend
- Membership Distribution
- Popular Classes
- Recent Payments
- Recent Check-Ins
- Recent Activity
- Quick Actions

### Member Management

Create and manage gym member profiles.

- Add members
- Edit members
- View member details
- Suspend members
- Reactivate members
- Delete members safely
- Search members
- Filter members
- Sort members
- Pagination

Member data can include:

- Member Number
- First Name
- Last Name
- Email
- Phone
- Address
- Date of Birth
- Emergency Contact
- Join Date
- Membership Status
- Notes

Member profiles can display:

- Active Membership
- Membership History
- Payment History
- Check-In History
- Class Bookings
- Class Attendance
- Outstanding Balance
- Recent Activity

### Membership Plans

Create reusable membership plans.

Examples:

- Daily
- Weekly
- Monthly
- Quarterly
- Semi-Annual
- Annual
- Custom

Plan information can include:

- Plan Name
- Duration
- Price
- Description
- Features
- Status

### Membership Management

Assign membership plans to members.

Membership features include:

- Create Membership
- Renew Membership
- Freeze Membership
- Resume Membership
- Cancel Membership
- Expiration Tracking
- Membership History

Membership statuses can include:

- Active
- Frozen
- Expired
- Cancelled
- Pending

### Payments

Manage gym payments.

Payment data can include:

- Member
- Membership
- Amount
- Payment Method
- Payment Status
- Payment Date
- Due Date
- Notes

Payment statuses:

- Pending
- Paid
- Partially Paid
- Refunded
- Failed

Track:

- Total Revenue
- Outstanding Payments
- Payment History
- Revenue by Membership Plan
- Revenue Trends

### Check-In System

Manage member gym entry records.

Features include:

- Select Member
- Search Member
- Check In
- Prevent Invalid Duplicate Check-Ins
- View Today's Check-Ins
- Check-In History
- Member Activity Tracking

### Trainer Management

Create and manage trainer profiles.

Trainer information can include:

- Name
- Email
- Phone
- Specializations
- Hire Date
- Status
- Biography
- Availability

Trainer profiles can display:

- Assigned Classes
- Weekly Schedule
- Member Assignments
- Workload
- Upcoming Classes

### Class Management

Create and manage fitness classes.

Examples:

- Yoga
- Pilates
- Spinning
- HIIT
- Boxing
- Cross Training
- Functional Training
- Strength Training
- Other

Class information can include:

- Class Name
- Trainer
- Room
- Capacity
- Date
- Start Time
- End Time
- Status
- Description

### Class Bookings

Allow members to register for classes.

Features include:

- Book Class
- Cancel Booking
- Capacity Validation
- Waiting List
- Booking Status
- Attendance Status
- Member Booking History

### Class Attendance

Track class participation.

Attendance statuses can include:

- Present
- Absent
- Cancelled
- No Show

### Schedule

Manage weekly gym class schedules.

Features:

- Trainer Assignment
- Room Assignment
- Start and End Times
- Capacity
- Conflict Detection
- Weekly Schedule View
- Class Filtering

The system can detect conflicts such as:

- Same trainer assigned to overlapping classes
- Same room assigned to overlapping classes

### Rooms

Manage gym rooms and training areas.

Room information can include:

- Name
- Capacity
- Description
- Status

### Expenses

Track gym expenses.

Expense categories can include:

- Rent
- Equipment
- Salaries
- Maintenance
- Utilities
- Marketing
- Cleaning
- Insurance
- Other

Track:

- Expense Amount
- Date
- Category
- Description
- Related Notes

### Revenue & Finance

Track financial performance.

Metrics can include:

- Membership Revenue
- Class Revenue
- Total Revenue
- Refunds
- Expenses
- Net Revenue
- Estimated Profit

### Calendar

View important gym dates.

The calendar can display:

- Fitness Classes
- Membership Expiration Dates
- Payment Due Dates
- Trainer Schedules

### Analytics

Analyze real application data.

Metrics can include:

- Total Members
- Active Memberships
- Membership Retention
- Monthly Revenue
- Average Revenue Per Member
- Check-In Frequency
- Class Occupancy
- Trainer Workload

Charts can include:

- Member Growth
- Membership Distribution
- Revenue Trend
- Check-In Trend
- Popular Classes
- Most Active Members
- Trainer Workload
- Membership Expirations
- Expense Distribution

### Reports

Generate gym management reports.

Available reports can include:

- Member Report
- Membership Report
- Revenue Report
- Payment Report
- Check-In Report
- Class Report
- Trainer Report
- Expense Report
- Attendance Report

### Search, Filters & Sorting

Search across:

- Members
- Trainers
- Classes
- Memberships
- Payments

Useful filters can include:

- Membership Status
- Membership Plan
- Trainer
- Class
- Payment Status
- Date Range
- Check-In Activity

Sorting options can include:

- Member Name
- Join Date
- Membership Expiration
- Revenue
- Trainer Name
- Class Date

### Import & Export

Manage local application data.

- Export all application data as JSON
- Import JSON backups
- Merge imported data
- Replace existing data
- Validate imported files
- Protect existing data from malformed imports

### Settings

Configure gym preferences.

Settings can include:

- Gym Name
- Currency
- Default Membership Duration
- Date Format
- Time Format
- Theme
- Compact Mode
- Default Table Page Size
- Check-In Settings

Supported currencies can include:

- USD
- EUR
- GBP
- TRY
- CAD
- AUD
- JPY

## Light & Dark Mode

The application includes:

- Light Theme
- Dark Theme

Theme preference can be stored in browser localStorage.

## Responsive Design

The interface is designed for:

- Smartphones
- Tablets
- Laptops
- Desktop Computers

Navigation, forms, tables, cards, charts, schedules, dialogs, and reports adapt to different screen sizes.

## Technologies

- HTML5
- CSS3
- Vanilla JavaScript
- Browser localStorage
- Chart.js
- Lucide Icons

The project does not require:

- React
- Next.js
- Vue
- Angular
- PHP
- Backend Server
- Database
- Authentication Server
- API Keys

## Modular Architecture

The project is separated into multiple HTML, CSS, and JavaScript files.

Example structure:

```text
gym-management-system-web-template/
│
├── index.html
├── members.html
├── membership-plans.html
├── memberships.html
├── payments.html
├── checkin.html
├── trainers.html
├── classes.html
├── bookings.html
├── attendance.html
├── schedule.html
├── rooms.html
├── expenses.html
├── revenue.html
├── calendar.html
├── analytics.html
├── reports.html
├── settings.html
│
└── assets/
    ├── css/
    │   ├── variables.css
    │   ├── base.css
    │   ├── layout.css
    │   ├── sidebar.css
    │   ├── header.css
    │   ├── components.css
    │   ├── cards.css
    │   ├── forms.css
    │   ├── tables.css
    │   ├── modals.css
    │   ├── calendar.css
    │   ├── charts.css
    │   └── responsive.css
    │
    └── js/
        ├── core/
        ├── ui/
        ├── data/
        └── modules/
```

## Data Storage

Application data can be stored using browser `localStorage`.

Stored data may include:

- Members
- Membership Plans
- Memberships
- Payments
- Trainers
- Classes
- Class Bookings
- Check-Ins
- Attendance Records
- Rooms
- Expenses
- Settings

Data remains available after page refreshes unless localStorage is cleared.

## Getting Started

Clone the repository:

```bash
git clone https://github.com/Erhanalp35/gym-management-system-web-template.git
```

Open the project folder:

```bash
cd gym-management-system-web-template
```

Then open:

```text
index.html
```

No backend or database installation is required.

## Demo Data

The template may initialize realistic demo data on the first launch.

Demo data can include:

- Members
- Membership Plans
- Active Memberships
- Expiring Memberships
- Trainers
- Fitness Classes
- Class Bookings
- Payments
- Check-Ins
- Expenses

Demo data should only initialize when no existing user data is present.

## Privacy

The application can operate entirely inside the browser.

It does not require:

- User Accounts
- Remote Databases
- Cloud Storage
- API Keys
- External Servers

## Screenshots

Add screenshots here:

```md
![Dashboard](assets/images/dashboard-preview.png)

![Members](assets/images/members-preview.png)

![Classes](assets/images/classes-preview.png)

![Analytics](assets/images/analytics-preview.png)
```

## Future Improvements

Possible future additions include:

- Real authentication
- Role-based permissions
- Backend database integration
- QR member cards
- QR check-in
- Online class booking
- Payment gateway integrations
- Member portal
- Trainer portal
- Automated payment reminders
- Membership expiration notifications
- PDF invoices
- Printable membership cards
- Multi-branch gym management
- Cloud synchronization

## Contributing

Contributions, bug reports, and feature suggestions are welcome.

Fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License.
