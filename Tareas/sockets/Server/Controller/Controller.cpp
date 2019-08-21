#include "include/rapidjson/reader.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "/home/brayanrv/TEC/Github/Tareas/Tareas/sockets/DataStructures/LinkedList/List.cpp"
#include "/home/brayanrv/TEC/Github/Tareas/Tareas/sockets/DataStructures/BinaryTree/BinaryTree.cpp"
#include <iostream>

using namespace rapidjson;
using namespace std;

struct MyHandler {
    bool Null() {
        cout << "Null()" << endl;
        return true;
    }
    bool Bool(bool b) {
        cout << "Bool(" << boolalpha << b << ")" << endl;
        return true;
    }
    bool Int(int i) {
        cout << "Int(" << i << ")" << endl;
        return true;
    }
    bool Uint(unsigned u) {
        cout << "Uint(" << u << ")" << endl;
        return true;
    }
    bool Int64(int64_t i) {
        cout << "Int64(" << i << ")" << endl;
        return true;
    }
    bool Uint64(uint64_t u) {
        cout << "Uint64(" << u << ")" << endl;
        return true;
    }
    bool Double(double d) {
        cout << "Double(" << d << ")" << endl;
        return true;
    }
    bool RawNumber(const char* str, SizeType length, bool copy) {
        cout << "Number(" << str << ", " << length << ", " << boolalpha << copy << ")" << endl;
        return true;
    }
    bool String(const char* str, SizeType length, bool copy) {
        cout << "String(" << str << ", " << length << ", " << boolalpha << copy << ")" << endl;
        return true;
    }
    bool StartObject() {
        cout << "StartObject()" << endl;
        return true;
    }
    bool Key(const char* str, SizeType length, bool copy) {
        cout << "Key(" << str << ", " << length << ", " << boolalpha << copy << ")" << endl;
        return true;
    }
    bool EndObject(SizeType memberCount) {
        cout << "EndObject(" << memberCount << ")" << endl;
        return true;
    }
    bool StartArray() {
        cout << "StartArray()" << endl;
        return true;
    }
    bool EndArray(SizeType elementCount) {
        cout << "EndArray(" << elementCount << ")" << endl;
        return true;
    }
};

void readJson(const char json[]){
    MyHandler handler;
    Reader reader;
    StringStream ss(json);
    reader.Parse(ss, handler);
}

void writeList(char type[], int data[], json[size]){
    //size = sizeof(data) + sizeof(type) + 10
    char json[size];
    int n = 0;
    json[n] = '{';
    json[n++] = ' \ ';
    json[n++] = '"';
    for (int i = 1; i < sizeof(type);i++) {
        json[n++] = type[i-1];
    }
    json[n++] = ' \ ';
    json[n++] = '"';
    json[n++] = ' ';
    json[n++] = ':';
    json[n++] = ' ';
    for (int j = 0; j < sizeof(data) ; j++) {
        json[n++] = data[j];
    }
    json[n++] = '"';
    json[n] = '}';





}
void writeTree(){

}