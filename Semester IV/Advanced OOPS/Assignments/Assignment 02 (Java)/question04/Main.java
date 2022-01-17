package java_assignment.question04;

/*
Consider a wrapper class for a numeric basic type. Check the support for
the following: conversion from i) basic type to object ii) object to basic type
iii) basic type to String iv) String (holding numeric data) to numeric object
v) object to String.
*/

public class Main {
    public static void main(String[] args) {
        Integer obj_int = 3;
        int integer = 5;

        // (i) basic type to object
        obj_int = Integer.valueOf(integer);
        System.out.println("basic type to object                            :: " + integer + " : " + obj_int);

        // (ii) object to basic type
        obj_int = 55;
        integer = obj_int.intValue();
        System.out.println("object to basic type                            :: " + obj_int + " : " + integer);

        // (iii) basic type to String
        integer = 91;
        String s = String.valueOf(integer);
        System.out.println("basic type to String                            :: " + integer + " : " + s);

        // (iv) String (holding numeric data) to numeric object
        s = "74";
        obj_int = Integer.parseInt(s);
        System.out.println("String (holding numeric data) to numeric object :: " + s + " : " + obj_int);

        // (v) object to String.
        obj_int = 7;
        s = Integer.toString(obj_int);
        System.out.println("object to String.                               :: " + obj_int + " : " + s);

    }
}
