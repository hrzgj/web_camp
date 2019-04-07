package com.chenyu.www.dao.impl;


import com.chenyu.www.po.User;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public interface UserDao {
     public User login(String userAccount, String password) ;
     public Boolean register(String userName, String password, String phone,String userAccount,String userIdNumber);
     Boolean findAccount(String userAccount);
     public User loginIdentity(String userAccount);
     public ArrayList<User> getMaterialsList();
     User load(User user , ResultSet rs) throws SQLException;
     Boolean update(User user);
}
