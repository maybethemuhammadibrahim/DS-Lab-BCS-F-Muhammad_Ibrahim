#include <iostream>
using namespace std;

class Task{
    string id;
    int priority;//1 being the most imp
    public:
    Task(string id="nil",int priority=1):id(id),priority(priority){}
    string getID(){return id;}
    int getPriority(){return priority;}
};

class Stack{
    int capacity;
    int top;//will bw a pointer
    Task*tasks;
    public:
    Stack(int capacity=100):capacity(capacity),top(-1){
        tasks=new Task[capacity];
    }
    ~Stack(){
        delete[]tasks;
    }
    void push(Task data){
        if(top<capacity-1){
            tasks[++top]=data;
            cout<<data.getID()<<" inserted into the stack"<<endl;
        }else cout<<"stack overflow"<<endl;
    }
    Task pop(){
        if(top>=0)return tasks[top--];
        cout<<"stack underflow"<<endl;
        return Task();
    }
    bool isEmpty(){
        return top==-1;
    }
};

class Queue{
    Task*tasks;
    int front,rear,capacity;
    public:
    Queue(int capacity=100):capacity(capacity),front(-1),rear(-1){
        tasks=new Task[capacity];
    }
    ~Queue(){
        delete[]tasks;
    }
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return (rear+1)%capacity==front;
    }
    void enqueue(Task t){
        if(isFull()){
            cout<<"queue full"<<endl;
            return;
        }
        if(front==-1)front=0;
        rear=(rear+1)%capacity;
        tasks[rear]=t;
        cout<<t.getID()<<" arrived in queue"<<endl;
    }
    Task dequeue(){
        if(isEmpty()){
            cout<<"queue empty"<<endl;
            return Task();
        }
        Task temp=tasks[front];
        if(front==rear)front=rear=-1;
        else front=(front+1)%capacity;
        return temp;
    }
    Task getAt(int i){
        return tasks[i];
    }
    int getFront(){return front;}
    int getRear(){return rear;}
    int getCapacity(){return capacity;}
    Task*getArray(){return tasks;}
};

class TaskManagement{
    Stack executionStack;
    Queue incomingTasks;
    public:
    void addNewTask(Task newTask){
        incomingTasks.enqueue(newTask);
    }
    void formExeStack(){
        if(incomingTasks.isEmpty()){
            cout<<"no tasks in queue"<<endl;
            return;
        }
        Task*arr=incomingTasks.getArray();
        int f=incomingTasks.getFront();
        int r=incomingTasks.getRear();
        int cap=incomingTasks.getCapacity();
        if(f==-1)return;
        int n=(r>=f)?(r-f+1):(cap-f+r+1);
        Task*temp=new Task[n];
        int idx=0;
        for(int i=0;i<n;i++){
            int index=(f+i)%cap;
            temp[idx++]=arr[index];
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(temp[j].getPriority()>temp[j+1].getPriority()){
                    Task t=temp[j];
                    temp[j]=temp[j+1];
                    temp[j+1]=t;
                }
            }
        }
        for(int i=0;i<n;i++)executionStack.push(temp[i]);
        delete[]temp;
    }
    void executeTasks(){
        while(!executionStack.isEmpty()){
            Task t=executionStack.pop();
            cout<<"executing "<<t.getID()<<" with priority "<<t.getPriority()<<endl;
        }
    }
};

int main(){
    TaskManagement tm;
    tm.addNewTask(Task("p1",3));
    tm.addNewTask(Task("p2",1));
    tm.addNewTask(Task("p3",2));
    tm.formExeStack();
    tm.executeTasks();
}
