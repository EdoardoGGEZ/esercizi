#include "recipesmodel.h"

RecipesModel::RecipesModel()
{
    recipes = {
        {
            tr("torta di mele"),
            "https://www.fattoincasadabenedetta.it/wp-content/uploads/2019/08/torta-di-mele-semplice-SITO-copertina.jpg",
            2,
            20,
        },
        {
            tr("tiramisu"),
            "https://www.giallozafferano.it/images/251-25105/Tiramisu-della-tradizione_650x433_wm.jpg",
            4,
            50,
        },
        {
            tr("torta della nonna"),
            "https://www.lucake.it/wp-content/uploads/2022/09/torta-della-nonna.jpg",
            3,
            30,
        },
    };
}

QVariant RecipesModel::data(const QModelIndex &index, int role) const
{
    int ind = index.row();
    Recipe rec = recipes[ind];
    switch(role)
    {
    case name:
        return rec.name;
    case imageFood:
        return rec.imageFood;
    case difficulty:
        return rec.difficulty;
    case time:
        return rec.time;
    default:
        return QVariant();
    }
}

int RecipesModel::rowCount(const QModelIndex &parent) const
{
    return recipes.count();
}

QHash<int, QByteArray> RecipesModel::roleNames() const
{
    return {
        {name, "name"},
        {imageFood, "imageFood"},
        {difficulty, "difficulty"},
        {time, "time"},
    };
}

QVariantMap RecipesModel::getRecipe(int index) const{
    QVariantMap ret;
    Recipe currentRecipe = recipes.at(index);

    ret["name"] = currentRecipe.name;
    ret["imageFood"] = currentRecipe.imageFood;
    ret["difficulty"] = currentRecipe.difficulty;
    ret["time"] = currentRecipe.time;
    return ret;
}
