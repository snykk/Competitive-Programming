#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SpellJournal {
public:
    static string journal;
};
string SpellJournal::journal = "";

// Find the Longest Common Subsequence (LCS)
int findLCS(string a, string b) {
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

class Spell {
public:
    virtual void revealPower() = 0;
    virtual ~Spell() {} // Virtual destructor
};

class Fireball : public Spell {
private:
    int power;
public:
    Fireball(int p) : power(p) {}
    void revealPower() override {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private:
    int power;
public:
    Frostbite(int p) : power(p) {}
    void revealPower() override {
        cout << "Frostbite: " << power << endl;
    }
};

class Waterbolt : public Spell {
private:
    int power;
public:
    Waterbolt(int p) : power(p) {}
    void revealPower() override {
        cout << "Waterbolt: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private:
    int power;
public:
    Thunderstorm(int p) : power(p) {}
    void revealPower() override {
        cout << "Thunderstorm: " << power << endl;
    }
};

class GenericSpell : public Spell {
private:
    string spellName;
public:
    GenericSpell(string name) : spellName(name) {}
    void revealPower() override {
        cout << findLCS(spellName, SpellJournal::journal) << endl;
    }
};

Spell* counterspell(string spellName, int power = 0) {
    if (spellName == "fire") return new Fireball(power);
    if (spellName == "frost") return new Frostbite(power);
    if (spellName == "water") return new Waterbolt(power);
    if (spellName == "thunder") return new Thunderstorm(power);
    return new GenericSpell(spellName);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string spellName;
        cin >> spellName;

        if (spellName == "fire" || spellName == "frost" || spellName == "water" || spellName == "thunder") {
            int power;
            cin >> power;
            Spell* spell = counterspell(spellName, power);
            spell->revealPower();
            delete spell;
        } else {
            string journalEntry;
            cin.ignore();  // Ignore newline left in buffer
            getline(cin, journalEntry); // Read full journal entry
            SpellJournal::journal = journalEntry;
            Spell* spell = counterspell(spellName);
            spell->revealPower();
            delete spell;
        }
    }
    return 0;
}
