#ifndef GENERATORWIDGET_H
#define GENERATORWIDGET_H

#include <string>
#include <vector>
#include <QLabel>

class GeneratorWidget {
    QLayout* parent;

    QString word;
    int category = 0;
    QChar letter;
    int position;
    std::vector<QLabel*> letter_widgets;
    std::vector<QString> dictionary[12];

public:
    GeneratorWidget(QLayout* p);
    ~GeneratorWidget();

    void LoadDictionary();
    void SetCategory(const int& cat) { category = cat; }
    QString GetRandomWord() const;
    void SetWord();
    void ClearWord();
    void CompleteWord();
    QChar GetLetter() const { return letter; }
    bool CheckLetter(const std::string& predictions);
};

#endif // GENERATORWIDGET_H
