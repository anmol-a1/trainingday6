#include<iostream>
#include<future>

int square(std::future<int>&ft){

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"\nHello From Square , I Have Started My Work\n";
    int number=ft.get();
    return number*number;
}
int factorial(int number){

    std::this_thread::sleep_for(std::chrono::seconds(2));
    if(number<0){
        throw std::runtime_error("\nnegative number error\n");
    }
    else if(number==0 || number==1){
        return 1;
    }
    else{
        return number*factorial(number-1);
    }

}
int main(){

    std::promise<int>pr;
    std::future<int>ft=pr.get_future();
    int val=4;
    std::future<int>result_ft=std::async(std::launch::async,&square,std::ref(ft));
    std::cout<<factorial(5);
    pr.set_value(val);
    std::cout<<"\nResult Square is : "<<result_ft.get();
    return 0;

}
