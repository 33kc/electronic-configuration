#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


std::unordered_map<std::string, int> elements = 
{
    {"Hydrogen", 1}, {"Helium", 2}, {"Lithium", 3}, {"Beryllium", 4}, {"Boron", 5}, {"Carbon", 6}, {"Nitrogen", 7}, {"Oxygen", 8}, {"Fluorine", 9}, {"Neon", 10},
    {"Sodium", 11}, {"Magnesium", 12}, {"Aluminium", 13}, {"Silicon", 14}, {"Phosphorus", 15}, {"Sulfur", 16}, {"Chlorine", 17}, {"Argon", 18}, {"Potassium", 19}, {"Calcium", 20},
    {"Scandium", 21}, {"Titanium", 22}, {"Vanadium", 23}, {"Chromium", 24}, {"Manganese", 25}, {"Iron", 26}, {"Cobalt", 27}, {"Nickel", 28}, {"Copper", 29}, {"Zinc", 30},
    {"Gallium", 31}, {"Germanium", 32}, {"Arsenic", 33}, {"Selenium", 34}, {"Bromine", 35}, {"Krypton", 36}, {"Rubidium", 37}, {"Strontium", 38}, {"Yttrium", 39}, {"Zirconium", 40},
    {"Niobium", 41}, {"Molybdenum", 42}, {"Technetium", 43}, {"Ruthenium", 44}, {"Rhodium", 45}, {"Palladium", 46}, {"Silver", 47}, {"Cadmium", 48}, {"Indium", 49}, {"Tin", 50},
    {"Antimony", 51}, {"Tellurium", 52}, {"Iodine", 53}, {"Xenon", 54}, {"Cesium", 55}, {"Barium", 56}, {"Lanthanum", 57}, {"Cerium", 58}, {"Praseodymium", 59}, {"Neodymium", 60},
    {"Promethium", 61}, {"Samarium", 62}, {"Europium", 63}, {"Gadolinium", 64}, {"Terbium", 65}, {"Dysprosium", 66}, {"Holmium", 67}, {"Erbium", 68}, {"Thulium", 69}, {"Ytterbium", 70},
    {"Lutetium", 71}, {"Hafnium", 72}, {"Tantalum", 73}, {"Tungsten", 74}, {"Rhenium", 75}, {"Osmium", 76}, {"Iridium", 77}, {"Platinum", 78}, {"Gold", 79}, {"Mercury", 80},
    {"Thallium", 81}, {"Lead", 82}, {"Bismuth", 83}, {"Polonium", 84}, {"Astatine", 85}, {"Radon", 86}, {"Francium", 87}, {"Radium", 88}, {"Actinium", 89}, {"Thorium", 90},
    {"Protactinium", 91}, {"Uranium", 92}, {"Neptunium", 93}, {"Plutonium", 94}, {"Americium", 95}, {"Curium", 96}, {"Berkelium", 97}, {"Californium", 98}, {"Einsteinium", 99}, {"Fermium", 100},
    {"Mendelevium", 101}, {"Nobelium", 102}, {"Lawrencium", 103}, {"Rutherfordium", 104}, {"Dubnium", 105}, {"Seaborgium", 106}, {"Bohrium", 107}, {"Hassium", 108}, {"Meitnerium", 109}, {"Darmstadtium", 110},
    {"Roentgenium", 111}, {"Copernicium", 112}, {"Nihonium", 113}, {"Flerovium", 114}, {"Moscovium", 115}, {"Livermorium", 116}, {"Tennessine", 117}, {"Oganesson", 118}
};


void calculateElectronConfiguration(int atomicNumber, std::vector<int>& s, std::vector<int>& p, std::vector<int>& d, std::vector<int>& f)
{

    const int subshellMaxElectrons[] = {2, 6, 10, 14};
    const std::vector<std::pair<int, int>> subshellOrder = {
        {1, 0}, {2, 0}, {2, 1}, {3, 0}, {3, 1}, {4, 0}, {3, 2}, {4, 1}, {5, 0}, {4, 2},
        {5, 1}, {6, 0}, {4, 3}, {5, 2}, {6, 1}, {7, 0}, {5, 3}, {6, 2}, {7, 1}, {6, 3},
        {7, 2}, {7, 3}
    };

    for (const auto& subshell : subshellOrder)
    {
        int shell = subshell.first;
        int type = subshell.second;

        int maxElectrons = subshellMaxElectrons[type];
        if (atomicNumber <= maxElectrons)
        {
            switch (type)
            {
                case 0: s[shell - 1] += atomicNumber; break;
                case 1: p[shell - 1] += atomicNumber; break;
                case 2: d[shell - 1] += atomicNumber; break;
                case 3: f[shell - 1] += atomicNumber; break;
            }
            break;
        }
        else
        {
            switch (type)
            {
                case 0: s[shell - 1] += maxElectrons; break;
                case 1: p[shell - 1] += maxElectrons; break;
                case 2: d[shell - 1] += maxElectrons; break;
                case 3: f[shell - 1] += maxElectrons; break;
            }
            atomicNumber -= maxElectrons;
        }
    }
}

std::string getShellName(int shell)
{
    switch (shell)
    {
        case 1: return "K";
        case 2: return "L";
        case 3: return "M";
        case 4: return "N";
        case 5: return "O";
        case 6: return "P";
        case 7: return "Q";
        default: return "";
    }
}

int main()
{
    std::string elementName;
    std::cout << "Enter the name of the element: ";
    std::cin >> elementName;


    elementName[0] = std::toupper(elementName[0]);
    for (size_t i = 1; i < elementName.length(); ++i)
    {
        elementName[i] = std::tolower(elementName[i]);
    }

    auto it = elements.find(elementName);
    if (it != elements.end())
    {
        int atomicNumber = it->second;

        std::vector<int> s(7, 0), p(7, 0), d(7, 0), f(7, 0);
        calculateElectronConfiguration(atomicNumber, s, p, d, f);

        std::cout << "Electron configuration for " << elementName << " (atomic number " << atomicNumber << "):" << std::endl;
        for (int i = 0; i < 7; ++i)
        {
            std::string shellConfig;
            if (s[i] > 0) shellConfig += "s" + std::to_string(s[i]) + " ";
            if (p[i] > 0) shellConfig += "p" + std::to_string(p[i]) + " ";
            if (d[i] > 0) shellConfig += "d" + std::to_string(d[i]) + " ";
            if (f[i] > 0) shellConfig += "f" + std::to_string(f[i]) + " ";

            if (!shellConfig.empty())
            {
                std::cout << "Shell " << getShellName(i + 1) << " = " << shellConfig << std::endl;
            }
        }
    }
    else
    {
        std::cout << "The element " << elementName << " is not in the table." << std::endl;
    }

    return 0;
}
