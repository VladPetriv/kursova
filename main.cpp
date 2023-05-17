#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <cmath>

class ShapeCalculator : public QWidget {
public:
    ShapeCalculator(QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);
        QLabel* shapeLabel = new QLabel("Виберіть фігуру, для обчислення обєму:");
        layout->addWidget(shapeLabel);
        QComboBox* shapeComboBox = new QComboBox();


        shapeComboBox->addItem("Виберіть фігуру");
        shapeComboBox->addItem("Куб");
        shapeComboBox->addItem("Піраміда");
        shapeComboBox->addItem("Призма");
        shapeComboBox->addItem("Паралелепіпед");
        shapeComboBox->addItem("Прямокутний паралелепіпед");
        shapeComboBox->addItem("Правильний тетраедр");
        shapeComboBox->addItem("Циліндр");
        shapeComboBox->addItem("Конус");

        layout->addWidget(shapeComboBox);


        connect(shapeComboBox, QOverload<int>::of(&QComboBox::activated), [this, shapeComboBox]() {
            int index = shapeComboBox->currentIndex();
            if (index == 1) {
                lengthLabel->setText("Введіть довжину сторони:");
                lengthLineEdit->setPlaceholderText("Довжина");
                lengthLabel->show();
                lengthLineEdit->show();

                // Видалення попередньо введених данних та результату при переході на Куб
                lengthLineEdit->clear();
                resultLabel->clear();

                // Приховування непотрібних полів
                baseLabel->hide();
                baseLineEdit->hide();
                heightLabel->hide();
                heightLineEdit->hide();

            } else if (index == 2) {
                lengthLabel->setText("Введіть довжину основи:");
                lengthLineEdit->setPlaceholderText("Довжина");
                lengthLabel->show();
                lengthLineEdit->show();

                baseLabel->setText("Введіть ширина основи:");
                baseLineEdit->setPlaceholderText("Ширина");
                baseLabel->show();
                baseLineEdit->show();


                heightLabel->setText("Введіть висота основи::");
                heightLineEdit->setPlaceholderText("Висота");
                heightLabel->show();
                heightLineEdit->show();



                // Видалення попередньо введених данних та результату при переході на Піраміду
                lengthLineEdit->clear();
                baseLineEdit->clear();
                heightLineEdit->clear();
                resultLabel->clear();
            } else if (index == 3) {
                lengthLabel->setText("Введіть площу основи призми:");
                lengthLineEdit->setPlaceholderText("Площа основи");
                lengthLabel->show();
                lengthLineEdit->show();

                baseLabel->setText("Введіть висоту призми::");
                baseLineEdit->setPlaceholderText("Висота основи");
                baseLabel->show();
                baseLineEdit->show();

                // Видалення попередньо введених данних та результату при переході на Призма
                lengthLineEdit->clear();
                baseLineEdit->clear();
                resultLabel->clear();

                // Приховування непотрібних полів
                heightLabel->hide();
                heightLineEdit->hide();
            } else if (index == 4) {
                lengthLabel->setText("Введіть довжину першої сторони паралелепіпеда:");
                lengthLineEdit->setPlaceholderText("Довжина першої сторони");
                lengthLabel->show();
                lengthLineEdit->show();

                baseLabel->setText("Введіть довжину другої сторони паралелепіпеда:");
                baseLineEdit->setPlaceholderText("Довжина другої сторони");
                baseLabel->show();
                baseLineEdit->show();


                heightLabel->setText("Введіть довжину третьої сторони паралелепіпеда:");
                heightLineEdit->setPlaceholderText("Довжина другої сторони");
                heightLabel->show();
                heightLineEdit->show();



                // Видалення попередньо введених данних та результату при переході на Паралелепіпед
                lengthLineEdit->clear();
                baseLineEdit->clear();
                heightLineEdit->clear();
                resultLabel->clear();
            } else if (index == 5) {
                lengthLabel->setText("Введіть довжину прямокутного паралелепіпеда:");
                lengthLineEdit->setPlaceholderText("Довжина першої сторони");
                lengthLabel->show();
                lengthLineEdit->show();

                baseLabel->setText("Введіть довжину другої сторони прямокутного паралелепіпеда:");
                baseLineEdit->setPlaceholderText("Довжина другої сторони");
                baseLabel->show();
                baseLineEdit->show();


                heightLabel->setText("Введіть висоту прямокутного паралелепіпеда:");
                heightLineEdit->setPlaceholderText("Висота");
                heightLabel->show();
                heightLineEdit->show();



                // Видалення попередньо введених данних та результату при переході на Прямокутний паралелепіпед
                lengthLineEdit->clear();
                baseLineEdit->clear();
                heightLineEdit->clear();
                resultLabel->clear();
            } else if (index == 6) {
                lengthLabel->setText("Введіть довжину ребра тетраедра:");
                lengthLineEdit->setPlaceholderText("Довжина");
                lengthLabel->show();
                lengthLineEdit->show();

                // Видалення попередньо введених данних та результату при переході на Правильний тетраедр
                lengthLineEdit->clear();
                resultLabel->clear();

                // Приховування непотрібних полів
                baseLabel->hide();
                baseLineEdit->hide();
                heightLabel->hide();
                heightLineEdit->hide();

            } else if (index == 7) {
                lengthLabel->setText("Введіть радіус циліндра:");
                lengthLineEdit->setPlaceholderText("Радіус");
                lengthLabel->show();
                lengthLineEdit->show();

                baseLabel->setText("Введіть висоту циліндра:");
                baseLineEdit->setPlaceholderText("Висота");
                baseLabel->show();
                baseLineEdit->show();

                // Видалення попередньо введених данних та результату при переході на Цилінд
                lengthLineEdit->clear();
                baseLineEdit->clear();
                resultLabel->clear();

                // Приховування непотрібних полів
                heightLabel->hide();
                heightLineEdit->hide();
            } else if (index == 8) {
                lengthLabel->setText("Введіть радіус конуса:");
                lengthLineEdit->setPlaceholderText("Радіус");
                lengthLabel->show();
                lengthLineEdit->show();

                baseLabel->setText("Введіть висоту конуса::");
                baseLineEdit->setPlaceholderText("Висота");
                baseLabel->show();
                baseLineEdit->show();

                // Видалення попередньо введених данних та результату при переході на Конус
                lengthLineEdit->clear();
                baseLineEdit->clear();
                resultLabel->clear();

                // Приховування непотрібних полів
                heightLabel->hide();
                heightLineEdit->hide();
            } else {
                lengthLabel->hide();
                lengthLineEdit->hide();
                baseLabel->hide();
                baseLineEdit->hide();
                heightLabel->hide();
                heightLineEdit->hide();


                // Видалення попередньо введених данних при переході на  іншу фігуру
                lengthLineEdit->clear();
                baseLineEdit->clear();
                heightLineEdit->clear();
                resultLabel->clear();

            }
        });


        lengthLabel = new QLabel("Enter the length of a side:");
        lengthLineEdit = new QLineEdit();
        lengthLineEdit->setValidator(new QDoubleValidator());
        lengthLineEdit->setPlaceholderText("Length");
        lengthLabel->hide();
        lengthLineEdit->hide();
        layout->addWidget(lengthLabel);
        layout->addWidget(lengthLineEdit);


        baseLabel = new QLabel("Enter the length of the base:");
        baseLineEdit = new QLineEdit();
        baseLineEdit->setValidator(new QDoubleValidator());
        baseLineEdit->setPlaceholderText("Base length");
        baseLabel->hide();
        baseLineEdit->hide();
        layout->addWidget(baseLabel);
        layout->addWidget(baseLineEdit);

        heightLabel = new QLabel("Enter the height:");
        heightLineEdit = new QLineEdit();
        heightLineEdit->setValidator(new QDoubleValidator());
        heightLineEdit->setPlaceholderText("Height");
        heightLabel->hide();
        heightLineEdit->hide();
        layout->addWidget(heightLabel);
        layout->addWidget(heightLineEdit);


        // Створення кнопки обчислення та додавання їй обробника
        QPushButton* calculateButton = new QPushButton("Calculate");
        layout->addWidget(calculateButton);
        connect(calculateButton, &QPushButton::clicked, this, &ShapeCalculator::calculateVolume);


        // Додавання поля длля відображення результату
        resultLabel = new QLabel();
        layout->addWidget(resultLabel);

        // Налаштування вікна
        setWindowTitle("Калькулятор обєму фігур");
        setFixedSize(500, 500);
    }

private:
    QLabel* lengthLabel;
    QLineEdit* lengthLineEdit;
    QLabel* baseLabel;
    QLineEdit* baseLineEdit;
    QLabel* heightLabel;
    QLineEdit* heightLineEdit;
    QLabel* resultLabel;

    void calculateVolume() {
        QString shape = static_cast<QComboBox*>(layout()->itemAt(1)->widget())->currentText();
        double volume = 0;
        if (shape == "Куб") {
            bool ok;
            double side = lengthLineEdit->text().toDouble(&ok);
            if (ok) {
                volume = std::pow(side, 3);
            }
        } else if (shape == "Піраміда") {
            bool ok1, ok2, ok3;
            double base = baseLineEdit->text().toDouble(&ok1);
            double width = baseLineEdit->text().toDouble(&ok2);
            double height = heightLineEdit->text().toDouble(&ok3);
            if (ok1 && ok2 && ok3) {
                volume = (base * width * height) / 3;
            }
        } else if (shape == "Призма") {
            bool ok1, ok2;
            double a = lengthLineEdit->text().toDouble(&ok1);
            double h = baseLineEdit->text().toDouble(&ok2);
            if (ok1 && ok2) {
                volume = a * h;
            }
        } else if (shape == "Паралелепіпед") {
            bool ok1, ok2, ok3;
            double a = baseLineEdit->text().toDouble(&ok1);
            double b = baseLineEdit->text().toDouble(&ok2);
            double c = heightLineEdit->text().toDouble(&ok3);
            if (ok1 && ok2 && ok3) {
                volume = a * b * c;
            }
        } else if (shape == "Прямокутний паралелепіпед") {
            bool ok1, ok2, ok3;
            double a = baseLineEdit->text().toDouble(&ok1);
            double b = baseLineEdit->text().toDouble(&ok2);
            double h = heightLineEdit->text().toDouble(&ok3);
            if (ok1 && ok2 && ok3) {
                volume = a * b * h;
            }
        } else if (shape == "Правильний тетраедр") {
            bool ok;
            double a = lengthLineEdit->text().toDouble(&ok);
            if (ok) {
                volume = (a * a * a) / (6 * sqrt(2));
            }
        } else if (shape == "Циліндр") {
            bool ok1, ok2;
            double r = lengthLineEdit->text().toDouble(&ok1);
            double h = baseLineEdit->text().toDouble(&ok2);
            if (ok1 && ok2) {
                volume = 3.14 * r * r * h;
            }
        } else if (shape == "Конус") {
            bool ok1, ok2;
            double r = lengthLineEdit->text().toDouble(&ok1);
            double h = baseLineEdit->text().toDouble(&ok2);
            if (ok1 && ok2) {
                volume = (3.14 * r * r * h) / 3;
            }
        }

        if (volume != 0) {
            resultLabel->setText("Обєм " + shape.toLower() + " дорівнює: " + QString::number(volume));
        } else {

            if (shape == "Виберіть фігуру"){
                resultLabel->setText("Будь ласка виберіть фігуру перед тим, як обчислювати обєм!");
            }else {
                resultLabel->setText("Введені невірні дані");
            }
        }
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ShapeCalculator calculator;
    calculator.show();

    return app.exec();
}


