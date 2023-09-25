#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

// Class for Ingredients
class Ingredient {
public:
    string name;
    string category;
    double quantity;
    string unit;

    Ingredient(const string& n, const string& cat, double qty, const string& u)
        : name(n), category(cat), quantity(qty), unit(u) {}

    void display() const {
        cout << name << ": " << quantity << " " << unit << " (" << category << ")\n";
    }
};

// Class for Recipe
class Recipe {
public:
    string title;
    vector<Ingredient> ingredients;
    string instructions;
    vector<string> tags;

    Recipe(const string& t, const string& instr, const vector<string>& tgs)
        : title(t), instructions(instr), tags(tgs) {}

    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

     void display() {
        cout << "Title: " <<title << "\n";
        cout << "Tags: ";
        for (const auto& tag : tags) {
            cout << tag << " ";
        }
        cout << "\nIngredients:\n";
        for (const auto& ingredient : ingredients) {
            ingredient.display();
        }
        cout << "Instructions:\n" << instructions << "\n";
    }
};

// Class for type of Recipe:

class RecipeType {
public:
    string typeName;

    RecipeType(const string& type) : typeName(type) {}

    void display() {
        cout << "Type: " << typeName << "\n";
    }
};

class VegetarianRecipe : public Recipe {
public:
    VegetarianRecipe(const string& t, const string& instr, const vector<string>& tgs)
        : Recipe(t, instr, tgs) {}
};

class NonVegetarianRecipe : public Recipe {
public:
    NonVegetarianRecipe(const string& t, const string& instr, const vector<string>& tgs)
        : Recipe(t, instr, tgs) {}
};

class ChineseRecipe : public Recipe {
public:
    ChineseRecipe(const string& t, const string& instr, const vector<string>& tgs)
        : Recipe(t, instr, tgs) {}
};

class ItalianRecipe : public Recipe {
public:
    ItalianRecipe(const string& t, const string& instr, const vector<string>& tgs)
        : Recipe(t, instr, tgs) {}
};

class DessertRecipe : public Recipe {
public:
    DessertRecipe(const string& t, const string& instr, const vector<string>& tgs)
        : Recipe(t, instr, tgs) {}
};

int main() {
    Ingredient tomato("Tomato", "Vegetable", 2.0, "pieces");
    Ingredient chicken("Chicken", "Meat", 1, "kg");
    Ingredient sugar("Sugar", "Sweetener", 0.25, "cup");

    
    NonVegetarianRecipe Biryani("Chicken Biryani", "Fired Chicken biryani", {"Non-Veg", "mightbe UnHealthy"});
    Biryani.addIngredient(chicken);

    ChineseRecipe stirFry("Vegetable Stir Fry", "Stir-fry vegetables with soy sauce.", {"Chinese", "Healthy"});
    stirFry.addIngredient(tomato);

    ItalianRecipe pasta("Spaghetti Pomodoro", "Boil pasta, sauté ingredients, mix.", {"Italian", "Pasta"});
    pasta.addIngredient(tomato);

    DessertRecipe cake("Chocolate Cake", "Bake a chocolate cake.", {"Dessert", "Chocolate"});
    cake.addIngredient(sugar);

    cout<<"Non-veg Recipe Details:\n";
    Biryani.display();

    cout << "Chinese Recipe Details:\n";
    stirFry.display();

    cout << "\nItalian Recipe Details:\n";
    pasta.display();

    cout << "\nDessert Recipe Details:\n";
    cake.display();

    return 0;
}