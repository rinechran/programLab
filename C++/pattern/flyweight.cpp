#include <iostream>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <string>



class Texture{
public:
    Texture(std::string str){
        this->str = str;
        std::cout<<str<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::string str;
};
class TextureCash{
public:
    TextureCash() = default;
    Texture* getObject(std::string str){
        Texture* rePtr = nullptr;
        auto i =this->obj.find(str);
        if(i!=obj.end()){
            rePtr = i->second;
        }
        else{
            rePtr = new Texture(str);
            obj.insert({str,rePtr});
        }
        return rePtr;
        
    }
    std::unordered_map<std::string, Texture*> obj;
    
};



int main(){
    Texture("1.jpg");
    Texture("1.jpg");
    Texture("1.jpg");
    Texture("1.jpg");
    Texture("1.jpg");
    Texture("1.jpg");
    
    std::cout<<"-------"<<std::endl;
    TextureCash temp;
    temp.getObject("1.jpg");
    temp.getObject("1.jpg");
    temp.getObject("1.jpg");
    temp.getObject("1.jpg");
    temp.getObject("2.jpg");
    temp.getObject("2.jpg");
    
}
