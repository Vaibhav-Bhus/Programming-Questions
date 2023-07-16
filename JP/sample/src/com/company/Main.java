package com.company;

import java.sql.*;

public class Main {

    public static void main(String[] args) throws SQLException {
        String jdbcURL = "jdbc:mysql://localhost:3306/sampledb?user=root&password=Pass&useUnicode=true&characterEncoding=UTF-8";

    String username = "root";
    String password = "root";

    String Username = "vabby";
        String Password = "vabby";
        String Email = "vabby";
        String FullName = "vabby";


    try {
        Connection connection = DriverManager.getConnection(jdbcURL, username, password);
        //Insert Data
//        String sql = "INSERT INTO User(username, password, fullname, email)"
//                + "VALUES ('v_bhus', 'password', 'Vaibhav Bhus', 'vaibhavbhus01@gmail.com' )";
//        Statement statement = connection.createStatement();
//        int rows = statement.executeUpdate(sql);
//
//        if (rows > 0){
//            System.out.println("Added successfully");
//        }
//
    // Insert Data by varible
//        String sql = "INSERT INTO User(username, password, fullname, email)"
//                + "VALUES (?, ?, ?, ?)";
//        PreparedStatement preparedStatement = connection.prepareStatement(sql);
//        preparedStatement.setString(1, Username);
//        preparedStatement.setString(2, Password);
//        preparedStatement.setString(3, FullName);
//        preparedStatement.setString(4, Email);
//        int rows = preparedStatement.executeUpdate();
//        if (rows > 0){
//            System.out.println("Added successfully");
//        }


        // Get Data Using Sql select Statement
//        String sql = "SELECT * from User";
//        Statement statement = connection.createStatement();
//        ResultSet resultSet = statement.executeQuery(sql);
//        while(resultSet.next()){
//            String Username1 = resultSet.getString(2);
//            String Password1 = resultSet.getString(3);
//            String FullName1 = resultSet.getString(4);
//            String Email1 = resultSet.getString(5);
//
//            System.out.println(Username1 + "   "+Password1 + "   "+FullName1 + "   "+Email1);
//        }


        //Update data
//        String sql = "UPDATE User SET password = 'Varun' WHERE username = 'vabby'";
//        Statement statement = connection.createStatement();
//        int rows = statement.executeUpdate(sql);
//        if (rows > 0){
//            System.out.println("User Updated");
//        }

           // getting some error in this type of query
//        String dummyNP = "ROOT";
//        String sql = "UPDATE User SET password='ROOT'";
//        PreparedStatement preparedStatement = connection.prepareStatement(sql);
//        preparedStatement.setString(1, dummyNP);
//
//        int rows = preparedStatement.executeUpdate(sql);
//        if (rows > 0){
//            System.out.println("User Updated");
//        }


        //Delete data

        String sql = "DELETE FROM User WHERE password='password'";
        Statement statement = connection.createStatement();
        int rows = statement.executeUpdate(sql);
        if (rows > 0){
            System.out.println("User Deleted");
        }

//        String dummyNP = "password";
//        PreparedStatement preparedStatement = connection.prepareStatement(sql);
//        preparedStatement.setString(1, dummyNP);
//
//        int rows = preparedStatement.executeUpdate(sql);
//        if (rows > 0){
//            System.out.println("User Updated");
//        }


        connection.close();

    }catch (SQLException ex){
        ex.printStackTrace();
        System.out.println("Sql Exception Occur");
    }

    }
}
