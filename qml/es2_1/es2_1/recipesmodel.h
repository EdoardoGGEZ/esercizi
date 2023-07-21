#pragma once

#include <QAbstractListModel>
#include <QQmlContext>

struct Recipe
{
    QString name;
    QString imageFood;
    int difficulty;
    int time;
};

class RecipesModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<Recipe> recipes;
public:
    enum Roles
    {
        name = Qt::UserRole + 1,
        imageFood,
        difficulty,
        time,
    };
    RecipesModel();
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE QVariantMap getRecipe(int index) const;
};
