#include "generatorwidget.h"
#include <QLayout>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <random>
#include <map>

std::string categories[12] = {
    "chartraits",
    "phystraits",
    "custom",
    "clothing",
    "emotions",
    "geopl",
    "geoworld",
    "names",
    "foods",
    "colours",
    "furniture",
    "items"
};

std::map<std::string, int> letter_mapping = {
    {"A", 0},
    {"Ą", 0},
    {'B', 1},
    {'C', 2},
    {'D', 3},
    {'E', 4},
    {'F', 5},
    {'G', 6},
    {'H', 7},
    {'I', 8},
    {'K', 9},
    {'L', 10},
    {'M', 11},
    {'N', 12},
    {'O', 13},
    {'P', 14},
    {'R', 15},
    {'S', 16},
    {'U', 17},
    {'W', 18},
    {'Y', 19},
    {'Z', 20}
};

GeneratorWidget::GeneratorWidget(QWidget* p): parent(p) {
    this->LoadDictionary();
    this->SetWord();
}

GeneratorWidget::~GeneratorWidget(){
    this->ClearWord();
}

void GeneratorWidget::LoadDictionary(){
    QFile file;
    QString word;
    std::string filename, dictpath = "../../../data/dict/";

    for (int i = 0; i < 12; i++){
        filename = dictpath + categories[i] + ".txt";
        file.setFileName(filename.c_str());

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            in.setCodec("UTF-8");

            while (!in.atEnd()) {
                word = in.readLine();
                dictionary[i].push_back(word);
            }
            file.close();
        }
    }
}

QString GeneratorWidget::GetRandomWord() const {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, dictionary[category].size() - 1);

    return dictionary[category][uni(rng)];
}

void GeneratorWidget::SetWord(){
    this->ClearWord();
    word = GetRandomWord();

    for (QChar c: word){
        QLabel* letter_widget = new QLabel;
        letter_widget->setStyleSheet(QString{"font-size: 25px;"
                                             "text-align: center"});
        letter_widget->setTextFormat(Qt::RichText);
        letter_widget->setText(c);
        parent->layout()->addWidget(letter_widget);
        letter_widgets.push_back(letter_widget);
    }
    position = 0;
    letter = word[0];
}

void GeneratorWidget::ClearWord(){
    for (QLabel* w: letter_widgets) {
        parent->layout()->removeWidget(w);
        delete w;
    }
    letter_widgets.clear();
}

void GeneratorWidget::CompleteWord(){
    SetWord();
}

bool GeneratorWidget::CheckLetter(const std::string& predictions){
    int confidence = 0;
    for (QChar c: predictions){
        if (c == letter) confidence += 1;
    }

    if (confidence > 10) {
        letter_widgets[position]->setStyleSheet(QString{"font-size: 25px;"
                                                        "color: rgb(0, 255, 0)"});
        position += 1;
        if (position < word.size()) letter = word[position];
        else this->CompleteWord();
        return true;
    }
    int saturation = (confidence * 255) / 10;
    letter_widgets[position]->setStyleSheet(QString{"font-size: 30px;"
                                                    "border-radius: 5px;"
                                                    "border-width: 2px;"
                                                    "border-color: white;"
                                                    "border-style: solid;"
                                                    "text-align: center;"
                                                    "color: rgb(%1, 255, %1)"}.arg(255-saturation));
    return false;
}

