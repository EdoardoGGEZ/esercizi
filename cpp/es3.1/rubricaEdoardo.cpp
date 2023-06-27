#include <iostream>
#include <vector>

using namespace std;

// contatto
struct Contact
{
    // attributi
    string name;
    string surname;
    string number;
    // friends
    friend ostream &operator<<(ostream &out, Contact &pt);
    friend bool operator==(Contact &first, Contact &second);
};

// filter padre
class AbstractFilter
{
public:
    virtual bool accept(const Contact &contact) const = 0;
};

// filtri figli
class ItalianPrefixFilter : public AbstractFilter
{
public:
    bool accept(const Contact &contact) const override
    {
        return contact.number.find("+39") == 0;
    }
};
class NameStartsWithFilter : public AbstractFilter
{
public:
    NameStartsWithFilter(const string &prefix) : m_prefix(prefix) {}
    bool accept(const Contact &contact) const override
    {
        return contact.name.find(m_prefix) == 0;
    }

private:
    string m_prefix;
};

// rubrica
class PhoneBook
{
private:
    // attributi
    vector<Contact> contacts;

public:
    // getters
    Contact getContacts(int index) { return contacts[index]; }
    // aggiungi
    void append(Contact add) { contacts.push_back(add); }
    // trova
    Contact *find(string name)
    {
        Contact *pt;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == name)
            {
                pt = &contacts[i];
            }
        }
        return pt;
    }
    // filtro
    vector<Contact *> filterBy(const AbstractFilter &filter)
    {
        vector<Contact *> result;
        for (auto &contact : contacts)
            if (filter.accept(contact))
                result.push_back(&contact);
        return result;
    }
    // friends
    friend ostream &operator<<(ostream &out, PhoneBook &pt);
};

// operator==
bool operator==(Contact &first, Contact &second)
{
    return (first.name == second.name) && (first.surname == second.surname) && (first.number == second.number);
}

// operator<<
ostream &operator<<(ostream &out, Contact &pt)
{
    out << "name: " << pt.name << " surname: " << pt.surname << " number di telefono: " << pt.number << endl;
    return out;
}
ostream &operator<<(ostream &out, PhoneBook &pt)
{
    for (int i = 0; i < pt.contacts.size(); i++)
    {
        out << pt.contacts[i] << endl;
    }
    return out;
}
int main()
{
    // test operator==
    {
        cout << "\n[operator==]";
        Contact test{"luca", "valenti", "1234567890"};
        Contact test1{"luca", "valenti", "1234567890"};
        if (test == test1)
            cout << "\n[OK]";
        else
            cout << "\n[FAIL]";
    }
    {
        Contact test{"gianni", "valenti", "1234567890"};
        Contact test1{"luca", "valenti", "1234567890"};
        if (test == test1)
            cout << "\n[FAIL]";
        else
            cout << "\n[OK]";
    }
    {
        Contact test{"luca", "valenti", "1234567890"};
        Contact test1{"luca", "ottaviano", "1234567890"};
        if (test == test1)
            cout << "\n[FAIL]";
        else
            cout << "\n[OK]";
    }
    {
        Contact test{"luca", "valenti", "1234567890"};
        Contact test1{"luca", "valenti", "0987564321"};
        if (test == test1)
            cout << "\n[FAIL]";
        else
            cout << "\n[OK]";
    }
    // test append
    {
        cout << "\n[append]";
        PhoneBook test;
        Contact testAdd{"gianni", "ottaviano", "0987654321"};
        test.append(testAdd);
        Contact testAdd1 = test.getContacts(0);
        if (testAdd == testAdd1)
            cout << "\n[OK]";
        else
            cout << "\n[FAIL]";
    }
    // test find
    {
        cout << "\n[find]";
        PhoneBook test;
        Contact testFind{"edoardo", "domina", "1234554321"};
        test.append(testFind);
        Contact testFind1 = *test.find("edoardo");
        if (testFind == testFind1)
            cout << "\n[OK]";
        else
            cout << "\n[FAIL]";
    }
    // test filter
    {
        cout << "\n[filter]";
        PhoneBook test;
        Contact testFilter{"lorenzo", "gini", "+396789009876"};
        test.append(testFilter);
        ItalianPrefixFilter filter;
        Contact testFilter1 = *test.filterBy(filter)[0];
        if (testFilter == testFilter1)
            cout << "\n[OK]";
        else
            cout << "\n[FAIL]";
    }
    {
        PhoneBook test;
        Contact testFilter{"lorenzo", "gini", "+396789009876"};
        test.append(testFilter);
        NameStartsWithFilter filter("lo");
        Contact testFilter1 = *test.filterBy(filter)[0];
        if (testFilter == testFilter1)
            cout << "\n[OK]";
        else
            cout << "\n[FAIL]";
    }
    return 0;
}