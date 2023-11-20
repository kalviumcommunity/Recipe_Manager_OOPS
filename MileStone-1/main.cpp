#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

// Class for Ingredients
class Ingredient
{
private:
    string name;
    string category;
    double quantity;
    string unit;
    static int ingredientCount; // Static member variabl

public:
    // Default constructor to allow creating an Ingredient without arguments
    Ingredient()
        : name(""), category(""), quantity(0.0), unit("") {}

    // Constructor to initialize Ingredient
    Ingredient(const string &n, const string &cat, double qty, const string &u)
        : name(n), category(cat), quantity(qty), unit(u)
    {
        ingredientCount++;
        cout << "Ingredient object created: " << name << "\n";
    }

    bool isEmpty() const
    {
        return name.empty();
    }

    void display() const
    {
        cout << name << ": " << quantity << " " << unit << " (" << category << ")\n";
    }
    // Static member function
    static void printIngredientCount()
    {
        cout << "Total NO.OF Ingredients: " << ingredientCount << endl;
    }

    // Destructor to perform cleanup
    ~Ingredient()
    {
        cout << "Ingredient object destroyed: " << name << "\n";
    }
};

int Ingredient::ingredientCount = 0; // Initialize the static member variable

// Recipe Class
class Recipe
{
public:
    string title;
    //    vector<Ingredient> ingredients;
    Ingredient ingredients[10];  // An array to store ingredients
    string instructions;
    vector<string> tags;

    Recipe(const string &title, const string &instructions, const vector<string> &tags)
    {
        // Using of THIS Pointer.
        this->title = title;
        this->instructions = instructions;
        this->tags = tags;
    }

    // void addIngredient(const Ingredient& ingredient) {
    //     ingredients.push_back(ingredient);
    // }

    void addIngredient(const Ingredient &ingredient)
    {
        for (int i = 0; i < 10; i++)
        {
            if (ingredients[i].isEmpty())
            {
                ingredients[i] = ingredient;
                break;
            }
        }
    }

    void display()
    {
        cout << "Title: " << title << "\n";
        cout << "Tags: ";
        for (const auto &tag : tags)
        {
            cout << tag << " ";
        }
        cout << "\nIngredients:\n";
        for (const auto &ingredient : ingredients)
        {
            if (!ingredient.isEmpty())
            {
                ingredient.display();
            }
        }
        cout << "Instructions:\n"
             << instructions << "\n";
    }
};

// Class for type of Recipe:
class RecipeType
{
public:
    string typeName;

    RecipeType(const string &type) : typeName(type) {}

    void display()
    {
        cout << "Type: " << typeName << "\n";
    }
};

class VegetarianRecipe : public Recipe
{
public:
    VegetarianRecipe(const string &t, const string &instr, const vector<string> &tgs)
        : Recipe(t, instr, tgs) {}
};

class NonVegetarianRecipe : public Recipe
{
public:
    NonVegetarianRecipe(const string &t, const string &instr, const vector<string> &tgs)
        : Recipe(t, instr, tgs) {}
};

class ChineseRecipe : public Recipe
{
public:
    ChineseRecipe(const string &t, const string &instr, const vector<string> &tgs)
        : Recipe(t, instr, tgs) {}
};

class ItalianRecipe : public Recipe
{
public:
    ItalianRecipe(const string &t, const string &instr, const vector<string> &tgs)
        : Recipe(t, instr, tgs) {}
};

class DessertRecipe : public Recipe
{
public:
    DessertRecipe(const string &t, const string &instr, const vector<string> &tgs)
        : Recipe(t, instr, tgs) {}
};

int main()
{
    Ingredient tomato("Tomato", "Vegetable", 2.0, "pieces");
    Ingredient chicken("Chicken", "Meat", 1, "kg");
    Ingredient sugar("Sugar", "Sweetener", 0.25, "cup");

    // Access the static member variable and function
    Ingredient::printIngredientCount();

    NonVegetarianRecipe Biryani("Chicken Biryani", "Fired Chicken biryani", {"Non-Veg", "mightbe UnHealthy"});
    Biryani.addIngredient(chicken);

    ChineseRecipe stirFry("Vegetable Stir Fry", "Stir-fry vegetables with soy sauce.", {"Chinese", "Healthy"});
    stirFry.addIngredient(tomato);

    ItalianRecipe pasta("Spaghetti Pomodoro", "Boil pasta, sauté ingredients, mix.", {"Italian", "Pasta"});
    pasta.addIngredient(tomato);

    DessertRecipe cake("Chocolate Cake", "Bake a chocolate cake.", {"Dessert", "Chocolate"});
    cake.addIngredient(sugar);

    cout << "Non-veg Recipe Details:\n";
    Biryani.display();

    cout << "Chinese Recipe Details:\n";
    stirFry.display();

    cout << "\nItalian Recipe Details:\n";
    pasta.display();

    cout << "\nDessert Recipe Details:\n";
    cake.display();

    return 0;
}