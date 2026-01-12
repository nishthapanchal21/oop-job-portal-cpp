#include <iostream>
#include <string>
#include <vector>
#include <memory> 
using namespace std;

/*demonstrates ENCAPSULATION by bundling data (name, email, etc.) and methods (build, display) together.*/
class Resume {
private:
    string name;
    string email;
    string phone;
    string experience;
    string education;
    string skills;
    bool isBuilt;

public:
    Resume() : isBuilt(false) {}  

    void build() {
        cout << "\n--- Resume Builder ---" << endl;
        cout << "Enter Full Name: ";
        getline(cin >> ws, name); 

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Work Experience (e.g., 'Software Engineer at Google'): ";
        getline(cin, experience);

        cout << "Enter Education (e.g., 'B.S. in Computer Science'): ";
        getline(cin, education);

        cout << "Enter Skills (e.g., 'C++, Python, SQL'): ";
        getline(cin, skills);

        isBuilt = true;
        cout << "Resume successfully built!" << endl;
    }

    void display() const {   
        if (!isBuilt) {
            cout << "Resume has not been built yet." << endl;
            return;
        }
        cout << "\n--- Generated Resume ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "\nWork Experience:\n" << experience << endl;
        cout << "\nEducation:\n" << education << endl;
        cout << "\nSkills:\n" << skills << endl;
        cout << "------------------------" << endl;
    }

    bool getIsBuilt() const {
        return isBuilt;
    }

    string getName() const {
        return name;
    }
};

/*  again ENCAPSULATION.  */

class Job {
private:
    string title;
    string companyName;
    string description;
    string skillsRequired;
    string contactEmail;
    int employerId; 

public:
    Job(string title, string company, string desc, string skills, string email, int empId)
        : title(title), companyName(company), description(desc), 
          skillsRequired(skills), contactEmail(email), employerId(empId) {}

    void display() const {
        cout << "\n--- Job Posting ---" << endl;
        cout << "Position: " << title << endl;
        cout << "Company: " << companyName << endl;
        cout << "Description: " << description << endl;
        cout << "Skills Required: " << skillsRequired << endl;
        cout << "Contact: " << contactEmail << endl;
        cout << "-------------------" << endl;
    }

    string getTitle() const {
        return title;
    }
};

/*base class for inheritance*/
class User {
protected:    
    static int nextId;
    int userId;
    string username;
    string password; 
    string email;

public:
    User(string uname, string pass, string mail)
        : userId(nextId++), username(uname), password(pass), email(mail) {}

    virtual ~User() {}

    virtual void displayDashboard() const = 0;

    bool login(string uname, string pass) const {
        return (username == uname && password == pass);
    }

    string getUsername() const {
        return username;
    }

    int getUserId() const {
        return userId;
    }
};

int User::nextId = 1;

/* derived class from user */

class JobSeeker : public User {
private:
    Resume myResume;

public:
    JobSeeker(string uname, string pass, string mail)
        : User(uname, pass, mail) {}

    void displayDashboard() const override {
        cout << "\n--- Job Seeker Dashboard ---" << endl;
        cout << "Welcome, " << username << "!" << endl;
        cout << "1. Build/Update Resume" << endl;
        cout << "2. View My Resume" << endl;
        cout << "3. View All Jobs" << endl;
        cout << "4. Logout" << endl;
        cout << "-----------------------------" << endl;
    }

    void buildResume() {
        myResume.build();
    }

    void viewResume() const {
        myResume.display();
    }

    // JobSeeker can apply
    void apply(const Job& job) const {
        if (!myResume.getIsBuilt()) {
            cout << "You must build your resume before applying!" << endl;
            return;
        }
        cout << "\nSuccessfully applied for: " << job.getTitle() << endl;
        cout << "Your resume (" << myResume.getName() << ") has been sent." << endl;
    }
};

/*  This INHERITS from the User class.*/

class Employer : public User {
private:
    vector<shared_ptr<Job>> postedJobs; 
    string companyName;

public:
    Employer(string uname, string pass, string mail, string company)
        : User(uname, pass, mail), companyName(company) {}

    void displayDashboard() const override {
        cout << "\n--- Employer Dashboard ---" << endl;
        cout << "Welcome, " << username << " (" << companyName << ")!" << endl;
        cout << "1. Post a New Job" << endl;
        cout << "2. View My Posted Jobs" << endl;
        cout << "3. Logout" << endl;
        cout << "--------------------------" << endl;
    }

    void postNewJob() {
        cout << "\n--- Post a New Job ---" << endl;
        string title, desc, skills;
        
        cout << "Enter Job Title/Position: ";
        getline(cin >> ws, title);

        cout << "Enter Job Description: ";
        getline(cin, desc);

        cout << "Enter Required Skills: ";
        getline(cin, skills);

        postedJobs.push_back(make_shared<Job>(title, companyName, desc, skills, email, userId));
        
        cout << "Job successfully posted!" << endl;
    }

    void viewPostedJobs() const {
        cout << "\n--- My Posted Jobs ---" << endl;
        if (postedJobs.empty()) {
            cout << "You have not posted any jobs yet." << endl;
            return;
        }
        for (const auto& job : postedJobs) {
            job->display();
        }
        cout << "----------------------" << endl;
    }
};

/*  It holds all the users and all the jobs.*/

class JobPortal {
private:
    vector<shared_ptr<User>> users;
    vector<shared_ptr<Job>> allJobs; 

    shared_ptr<User> findUser(const string& username) {
        for (const auto& user : users) {
            if (user->getUsername() == username) {
                return user;
            }
        }
        return nullptr; 
    }

public:
    void run() {
        cout << "Welcome to the C++ Job Portal!" << endl;
        while (true) {
            cout << "\n--- Main Menu ---" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter choice: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                loginMenu();
            } else if (choice == 2) {
                registerMenu();
            } else if (choice == 3) {
                cout << "Thank you for using the Job Portal. Goodbye!" << endl;
                break;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

private:
    void registerMenu() {
        cout << "\n--- Registration ---" << endl;
        cout << "1. Register as Job Seeker" << endl;
        cout << "2. Register as Employer" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        
        string username, password, email;
        cout << "Enter username: ";
        cin >> username;

        if (findUser(username)) {
            cout << "Error: Username already exists." << endl;
            return;
        }

        cout << "Enter password: ";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;

        if (choice == 1) {
            users.push_back(make_shared<JobSeeker>(username, password, email));
            cout << "Job Seeker registration successful!" << endl;
        } else if (choice == 2) {
            string companyName;
            cout << "Enter your company name: ";
            getline(cin >> ws, companyName);
            users.push_back(make_shared<Employer>(username, password, email, companyName));
            cout << "Employer registration successful!" << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    void loginMenu() {
        cout << "\n--- Login ---" << endl;
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        shared_ptr<User> user = findUser(username);
        
        if (user && user->login(username, password)) {
            cout << "Login successful!" << endl;
            if (auto seeker = dynamic_pointer_cast<JobSeeker>(user)) {
                jobSeekerLoop(seeker);
            } else if (auto employer = dynamic_pointer_cast<Employer>(user)) {
                employerLoop(employer);
            }
        } else {
            cout << "Error: Invalid username or password." << endl;
        }
    }

    void jobSeekerLoop(shared_ptr<JobSeeker> seeker) {
        while (true) {
            seeker->displayDashboard();
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                seeker->buildResume();
            } else if (choice == 2) {
                seeker->viewResume();
            } else if (choice == 3) {
                viewAllJobsMenu(seeker);
            } else if (choice == 4) {
                cout << "Logging out..." << endl;
                break;
            } else {
                cout << "Invalid choice." << endl;
            }
        }
    }

    void employerLoop(shared_ptr<Employer> employer) {
        while (true) {
            employer->displayDashboard();
            cout << "Enter choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                employer->postNewJob();
            } else if (choice == 2) {
                employer->viewPostedJobs();
            } else if (choice == 3) {
                cout << "Logging out..." << endl;
                break;
            } else {
                cout << "Invalid choice." << endl;
            }
        }
    }

    void viewAllJobsMenu(shared_ptr<JobSeeker> seeker) {
        cout << "\n--- All Available Jobs ---" << endl;
        
        if (allJobs.empty()) {
             allJobs.push_back(make_shared<Job>("C++ Developer", "Tech Corp", "Write C++ code", "C++, OOP", "hr@tech.com", 99));
             allJobs.push_back(make_shared<Job>("Web Developer", "Web Inc", "Build websites", "HTML, JS", "hr@web.com", 98));
        }

        if (allJobs.empty()) {
            cout << "No jobs are currently available. Check back later!" << endl;
            return;
        }

        for (int i = 0; i < allJobs.size(); ++i) {
            cout << "\nJob #" << (i + 1) << endl;
            allJobs[i]->display();
        }

        cout << "\nEnter the Job # to apply (or 0 to go back): ";
        int choice;
        cin >> choice;

        if (choice > 0 && choice <= allJobs.size()) {            
            seeker->apply(*allJobs[choice - 1]);
        } else if (choice == 0) {
            return;
        } else {
            cout << "Invalid job number." << endl;
        }
    }
};

int main() {
    JobPortal portal;
    portal.run();
    return 0;
}