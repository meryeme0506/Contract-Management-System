#include <string>
#include <list>
#include <ctime>
#include <iostream>
#include "Deal.h"
#include "Portfolio.h"
#include "Facility.h"
#include "Part.h"
#include "Institution.h"

using namespace std;

// Function to safely input a non-negative amount of money.
void inputAmount(float& amount) {
    bool validInput = false;
    while (!validInput) {
        cout << "Enter the amount: ";
        cin >> amount;
        if (amount < 0) {
            cerr << "Error: Amount cannot be negative. Please enter a non-negative amount." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            validInput = true; 
      }
  }
}


// Function to safely input a part, ensuring that part amount is less than facility amount.
void inputPart(float facilityAmount, float& partAmount) {
    bool validInput = false;
    while (!validInput) {
        try {
            inputAmount(partAmount);
            if (partAmount > facilityAmount) {
                throw invalid_argument("Part amount cannot be more than facility amount");
            }
            validInput = true; 
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << ". Please enter a valid part amount." << endl;
        }
    }
}

int main(int argc, char const *argv[]) {

  Deal d[100];
  Deal d1;
  Institution lenders[100], borrowers[100];
  Facility facility[200];
  //
  Facility facil;
  list<Institution> l, f;
  list<Institution> t;
  Institution tmp, agent, borrower, lender;
  string name, quest, dealID, curr, id, transaction, lend;
  float amount, projectAmount, rate, interest;
  int i,n,o, len, borr, fa = 0;
  tm start, end;

  // boucle principale
  quest = "y";
  while (quest == "y") {
    cout << "Which transaction do you want to do ? ('deal' to add a deal, 'borrower' to add a borrower, 'lender' to add a lender, 'facility' to add a facility to a deal, 'part' to add a part, 'portfolio' to check the interest on a facility) " << endl;
    cin >> transaction;
    if (transaction == "deal") {
        cout << "Enter the borrower's name : " << endl;
        cin >> name;
        int p = 0;
        string bname = borrowers[p].getName();
        while (bname != name && p <= borr) {
          p++;
          bname = borrowers[p].getName();
        }
        borrower = borrowers[p];

        cout << "Enter the agent's name : " << endl;
        cin >> name;
        int e = 0;
        string aname = lenders[e].getName();
        while (aname != name && e <= len) {
          e++;
          aname = lenders[e].getName();
        }
        agent = lenders[e];

        int j;
        cout << "How many lenders will be in the pool ?" << endl;
        cin >> j;
        for (size_t k = 0; k < j; k++) {
          cout << "Enter the lender's name : " << endl;
          cin >> name;
          int c = 0;
          string aname = lenders[c].getName();
          while (aname != name && c <= len) {
            c++;
            aname = lenders[c].getName();
          }
          tmp = lenders[c];
          t.emplace_back(tmp);
        }

        bool dealExists;
        do {
            cout << "Deal ID ?" << endl;
            cin >> dealID;

            // Check for duplicate deal ID.
            dealExists = false;
            for (int i = 0; i < n; ++i) {
                if (d[i].getContract() == dealID) {
                    cerr << "Error: A deal with this ID already exists. Please enter a different ID." << endl;
                    dealExists = true;
                    break;
                }
            }
        } while (dealExists);

        cout << "currency of the deal ?" << endl;
        cin >> curr;

        cout << "Start year ?" << endl;
        cin >> o;
        start.tm_year = o - 1900;

        do {
          cout << "Start month (0-11) ?" << endl;
          cin >> start.tm_mon;

          // Check for valid month (0-11)
          if (start.tm_mon < 0 || start.tm_mon > 11) {
              cerr << "Error: Invalid month. Please enter a valid month (0-11)." << endl;
          }
        }while (start.tm_mon < 0 || start.tm_mon > 11);

        do {
            cout << "Start day (1-31) ?" << endl;
            cin >> start.tm_mday;

            // Check for valid month (0-11)
            if (start.tm_mday < 1 || start.tm_mday > 31) {
                cerr << "Error: Invalid day. Please enter a valid day (1-31)." << endl;
            }
        }while (start.tm_mday < 1 || start.tm_mday > 31);

        cout << "End year ?" << endl;
        cin >> o;
        end.tm_year = o - 1900;

        do {
          cout << "End month (0-11) ?" << endl;
          cin >> end.tm_mon;
          // Check for valid month (0-11)
          if (end.tm_mon < 0 || end.tm_mon > 11) {
              cerr << "Error: Invalid month. Please enter a valid month (0-11)." << endl;
          }
        }while (end.tm_mon < 0 || end.tm_mon > 11);

        do {
            cout << "end day (1-31) ?" << endl;
            cin >> end.tm_mday;

            // Check for valid month (0-11)
            if (end.tm_mday < 1 || end.tm_mday > 31) {
                cerr << "Error: Invalid day. Please enter a valid day (1-31)." << endl;
            }
        }while (end.tm_mday < 1 || end.tm_mday > 31);

        d[n] = Deal(dealID, agent, t, borrower, projectAmount, curr, start, end);
        n++;
    } else if (transaction == "borrower") {
        cout << "Enter the borrower's name : " << endl;
        cin >> name;
        inputAmount(projectAmount);
        borrower = Institution(name, projectAmount, "borrower");
        borrowers[borr] = borrower;
        borr++;
    } else if (transaction == "lender") {
        cout << "Enter the lender's name : " << endl;
        cin >> lend;
        cout << "Enter the disposable amount : " << endl;
        cin >> amount;
        lender = Institution(lend, amount, "lender");
        lenders[len] = lender;
        len++;
    } else if (transaction == "facility") {
        cout << "To which deal do you want to add a facility ? (Deal ID) " << endl;
        cin >> dealID;
        int cpt = 0;
        string dname = d[cpt].getContract();
        while (dname != dealID && cpt <= n) {
          cpt++;
          dname = d[cpt].getContract();
        }
        Deal deal = d[cpt];

        cout << "Start year ?" << endl;
        cin >> o;
        start.tm_year = o - 1900;

        do {
          cout << "Start month (0-11) ?" << endl;
          cin >> start.tm_mon;

          // Check for valid month (0-11)
          if (start.tm_mon < 0 || start.tm_mon > 11) {
              cerr << "Error: Invalid month. Please enter a valid month (0-11)." << endl;
          }
        }while (start.tm_mon < 0 || start.tm_mon > 11);

        do {
            cout << "Start day (1-31) ?" << endl;
            cin >> start.tm_mday;

            // Check for valid month (0-11)
            if (start.tm_mday < 1 || start.tm_mday > 31) {
                cerr << "Error: Invalid day. Please enter a valid day (1-31)." << endl;
            }
        }while (start.tm_mday < 1 || start.tm_mday > 31);


        cout << "End year ?" << endl;
        cin >> o;
        end.tm_year = o - 1900;

        do {
          cout << "End month (0-11) ?" << endl;
          cin >> end.tm_mon;
          // Check for valid month (0-11)
          if (end.tm_mon < 0 || end.tm_mon > 11) {
              cerr << "Error: Invalid month. Please enter a valid month (0-11)." << endl;
          }
        }while (end.tm_mon < 0 || end.tm_mon > 11);

        do {
            cout << "end day (1-31) ?" << endl;
            cin >> end.tm_mday;

            // Check for valid month (0-11)
            if (end.tm_mday < 1 || end.tm_mday > 31) {
                cerr << "Error: Invalid day. Please enter a valid day (1-31)." << endl;
            }
        }while (end.tm_mday < 1 || end.tm_mday > 31);

        cout << "Interest rate ?" << endl;
        cin >> rate;

        cout << "currency ?" << endl;
        cin >> curr;

        bool validAmount = false;
        while (!validAmount) {
            try {
                // Request user input for amount
                inputAmount(amount);

                // Check if the amount exceeds the deal amount
                if (amount > d[cpt].getAmount()) {
                    throw invalid_argument("Facility amount cannot be more than deal amount");
                }

                validAmount = true; // Set validAmount to true to exit the loop
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << ". Please enter a valid amount." << endl;
                // Display error message to the user and prompt for re-entering the amount
            }
        }

        bool facilityExists;
        do {
            cout << "Facility ID ?" << endl;
            cin >> id;

            // Check if a facility with the same ID already exists
            facilityExists = false;
            for (int i = 0; i < fa; ++i) {
                if (facility[i].getName() == id) {
                    cerr << "Error: A facility with this ID already exists. Please enter a different ID." << endl;
                    facilityExists = true;
                    break; // Exit the for loop if a facility with the same ID is found
                }
            }
        } while (facilityExists);


        int j;
        l.clear();
        cout << "How many lenders will be participating in the facility ?" << endl;
        cin >> j;
        for (size_t k = 0; k < j; k++) {
          cout << "Enter the lender's name : " << endl;
          cin >> name;
          int fac = 0;
          string lend = lenders[fac].getName();
          while (lend != name && fac <= len) {
            fac++;
            lend = lenders[fac].getName();
          }
          Institution lender = lenders[fac];
          l.emplace_back(lender);
        }
        facility[fa] = Facility(id, start, end, amount, rate, curr, l);
        deal.addFacility(facility[fa]);
        fa++;
    } else if (transaction == "part") {
        cout << "To which facility do you want to add a part ? (ID) " << endl;
        cin >> id;
        int c = 0;
        string fname = facility[c].getName();
        while (fname != id && c <= fa) {
          c++;
          fname = facility[c].getName();
        }
        // Reference to Facility
        Facility &facil = facility[c];

        cout << "Start year ?" << endl;
        cin >> o;
        start.tm_year = o - 1900;

        cout << "Start month (0-11) ?" << endl;
        cin >> start.tm_mon;

        cout << "Start day (1-31) ?" << endl;
        cin >> start.tm_mday;

        cout << "End year ?" << endl;
        cin >> o;
        end.tm_year = o - 1900;

        cout << "End month (0-11) ?" << endl;
        cin >> end.tm_mon;

        cout << "End day (1-31) ?" << endl;
        cin >> end.tm_mday;

        inputPart(facility[c].getCurrAmount(), amount);


        Part p = Part(amount, start, end);
        // Add part to facility
        facil.addPart(p); 
    } else if (transaction == "portfolio") {
        cout << "Which facility do you want to check the interests of ? (ID) " << endl;
        cin >> id;
        int port = 0;
        string fname = facility[port].getName();
        while (fname != id) {
          port++;
          fname = facility[port].getName();
        }
        facil = facility[port];
        interest = facil.getPortfolio().getInterest();
        cout << interest << endl;
    }

    cout << "Do you want to make another transaction ? (y/n) " << endl;
    cin >> quest;
  }

  return 0;
}
