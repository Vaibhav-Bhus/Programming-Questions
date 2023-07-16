package com.company;

class Animal1 {
    public String taxonomyId;
    private String breedName;
    public static int counter =100;
    public Animal1(){
        this.breedName="BloodHound";
        Animal1.counter++;
        this.taxonomyId="A"+ ++Animal1.counter;
    }
    public void display(){
        System.out.println("taxonomyId:"+this.taxonomyId);
    }
}


class Dog extends Animal1{
    private String dogBreedName;
    private static int dogCount = 1;
    @Override
    public void display(){
        super.display();
        System.out.println("value of dog count "+ ++dogCount);
    }

}
public class Animal{
    public static void main(String[] args) {
     Animal1 animalObj = new Dog();
     Animal1.counter++;
     animalObj.display();
    }
}