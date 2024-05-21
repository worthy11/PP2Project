#include "generatorwidget.h"
#include <QLayout>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <random>

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

std::map<QChar, int> letter_map{
    {L'A', 0},
    {QChar(0x0104), 0},
    {L'B', 1},
    {L'C', 2},
    {QChar(0x0106), 2},
    {L'D', 20},
    {L'E', 4},
    {QChar(0x0118), 4},
    {L'F', 5},
    {L'G', 6},
    {L'H', 7},
    {L'I', 8},
    {L'J', 8},
    {L'K', 9},
    {L'L', 10},
    {QChar(0x0141), 10},
    {L'M', 11},
    {L'N', 12},
    {QChar(0x0143), 12},
    {L'O', 13},
    {QChar(0x00D3), 13},
    {L'P', 14},
    {L'R', 15},
    {L'S', 16},
    {QChar(0x015A), 16},
    {L'T', 5},
    {L'U', 17},
    {L'W', 18},
    {L'Y', 19},
    {L'Z', 20},
    {QChar(0x0179), 20},
    {QChar(0x017B), 20}
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
    int mapping = letter_map[letter];
    for (QChar c: predictions){
        if (c != QChar(' ') && letter_map[c] == mapping) confidence += 1;
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

