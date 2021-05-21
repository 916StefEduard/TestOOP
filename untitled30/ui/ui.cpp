#include <QLineEdit>
#include <QApplication>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "ui.h"


int ui::construct(int argc,char**argv){
    QApplication app(argc,argv);
    auto listwidget=new QListWidget();
    service::load_data();
    auto v=std::vector<vegetable>(service::get_vegetables());
    auto families=std::vector<string>();
    auto copy=std::vector<string>();
    for(auto & i : v){
        families.push_back(i.family);
    }
    std::sort(families.begin(),families.end(),[](const string& element1,const string& element2){
        return element1<element2;
    });
    for(auto &i:families){
        if(std::find(copy.begin(),copy.end(),i)==copy.end()){
            copy.push_back(i);
        }
    }
    for(const auto &element:copy){
        auto item=new QListWidgetItem();
        item->setText(QString::fromStdString(element));
        listwidget->addItem(item);
    }
    QObject::connect(listwidget,&QListWidget::itemClicked,[this](auto item){
        auto list=new QListWidget();
        string text=item->text().toStdString();
        for(auto &element:service::get_vegetables_with_family(text)){
            list->addItem(QString::fromStdString(element.to_string()));
        }
        list->show();
    });
    auto widget=new QWidget;
    auto layout=new QVBoxLayout();
    widget->setLayout(layout);
    layout->addWidget(listwidget);
    auto line=new QLineEdit();
    layout->addWidget(line);
    auto *button=new QPushButton("search");
    layout->addWidget(button);
    auto *new_label=new QLabel();
    layout->addWidget(new_label);
    QObject::connect(button,&QPushButton::clicked,[=](){
       bool found=false;
       for(auto &item:service::get_vegetables()){
           if(item.name==line->text().toStdString()){
                found=true;
                for(int i=0;i<listwidget->count();++i){
                    if(listwidget->item(i)->text().toStdString()==item.family){
                        listwidget->item(i)->setBackground(Qt::green);
                        new_label->setText(QString::fromStdString(item.parts));
                    }else{
                        listwidget->item(i)->setBackground(Qt::white);
                    }
                }
           }
       }
    });
    widget->show();
    return app.exec();
}