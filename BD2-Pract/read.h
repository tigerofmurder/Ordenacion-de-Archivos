#ifndef READ_H
#define READ_H

#include <bits/stdc++.h>
#include <QString>
#include <QDebug>

using namespace  std;

class Node{
public:
    int registro;
    QString cuenta,name,saldo;
public:
    Node(int a,string b,string c,string d){
        cuenta=QString::fromStdString(b);
        name=QString::fromStdString(c);
        saldo=QString::fromStdString(d);
        registro=a;
    }
    bool operator!=(const Node &v1){
        return registro!=v1.registro;
    }
    bool operator==(const Node &v1){
        return registro==v1.registro;
    }
    bool operator>(const Node &v1){
        return registro>v1.registro;
    }
    bool operator<(const Node &v1){
        return registro<v1.registro;
    }
};



class Read{
public:
    list<Node*> Registre;
    list<Node*> Delete;
    int i;
public:
    Read(){
        i=0;
    }
    auto find(int a,list<Node*> &abc){
        for (auto it=abc.begin();it!=abc.end();it++){
            if((*(it))->registro==a){
                return *it;
            }
        }
    }
    void insert(string b,string c,string d){
        if(Delete.empty()){
            Registre.push_back(new Node(i,b,c,d));
        }
        else{
            int a=(*(*(Delete.begin()))).registro;
            auto ite=find(a,Registre);
            cout<<a<<"->"<<ite->registro<<" "<<ite->cuenta.toStdString()<<" "<<ite->name.toStdString()<<" ";
            ite->registro=i;
            ite->cuenta=QString::fromStdString(b);
            ite->name=QString::fromStdString(c);
            ite->saldo=QString::fromStdString(d);
            Delete.pop_front();
        }
        i++;
    }
    void Lecture(){
        ifstream is("Registros.txt");
        if(is){
            string line;
            while (getline(is,line)) {
                stringstream ss(line);
                string primer;
                getline(ss,primer,',');
                string nombre;
                getline(ss,nombre,',');
                string valor;
                getline(ss,valor,',');
                insert(primer,nombre,valor);
            }
            is.close();
        }
    }

    void Delete1(int a){
        Registre.remove(find(a,Registre));
    }
    void Delete2(int a){
        auto ite=find(a,Registre);
        auto it=Registre.rbegin();
        swap(**it,*ite);
        Registre.pop_back();
    }
    void Delete3(int a){
        auto ite=find(a,Registre);

        ite->cuenta="";
        ite->name="";
        ite->saldo="";

        Delete.push_back(ite);
        //cout<<"AQUI"<<endl;
        //cout<<(*(Delete.begin()))->registro<<endl;
    }
};

#endif // READ_H
