package com.chenyu.www.po;

public class User {
    private  int id;
    private  String userName;
    private  String userAccount;
    private  String userPhone;
    private  String userPassword;
    private  String identity;
    private  String userIdNumber;

    public String getIdentity() {
        return identity;
    }

    public void setIdentity(String identity) {
        this.identity = identity;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getUserAccount() {
        return userAccount;
    }

    public void setUserAccount(String userAccount) {
        this.userAccount = userAccount;
    }

    public String getUserPhone() {
        return userPhone;
    }

    public void setUserPhone(String userPhone) {
        this.userPhone = userPhone;
    }

    public String getUserIdNumber() {
        return userIdNumber;
    }

    public void setUserIdNumber(String userIdNumber) {
        this.userIdNumber = userIdNumber;
    }



    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }



    public String getUserPassword() {
        return userPassword;
    }

    public void setUserPassword(String userPassword) {
        this.userPassword = userPassword;
    }




}
