package com.chenyu.www.service;

import com.chenyu.www.dao.impl.UserDao;
import com.chenyu.www.dao.impl.UserDaoImpl;
import com.chenyu.www.po.User;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class UserService {

    public void login(String userAccount, String userPassword,HttpServletRequest request,HttpServletResponse response) throws IOException, ServletException {
        UserDao u = new UserDaoImpl();
        User user =u.login(userAccount,userPassword);
        if(user!=null)
        {
            request.getSession().setAttribute("user",user);
            request.getRequestDispatcher("LoginSuccess.jsp").forward(request,response);
        }
        else
        {
            response.sendRedirect("/hotel_war_exploded/LoginFail.jsp");
        }

    }

    public Boolean isRight(String user)
    {
        if (user.length() > 5 && user.length() < 21
                && user.matches("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{6,20}$")) {
            return true;
        } else {
            return false;
        }
    }

    public  Boolean isPhoneRight(String phone)
    {
         return phone.matches("[0-9]{11}");

    }

    public Boolean isUserIdNumberRight(String userIdNumber)
    {
       return userIdNumber.matches("[0-9]{18}");


    }

    public void Register(String userName, String usePassword, String usePhone, String userAccount,String userIdNumber, HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (!isRight(userAccount))
        {
            request.setAttribute("account","账户格式错误");
            request.getRequestDispatcher("Register.jsp").forward(request,response);
            return;
        }
       if(!isRight(usePassword))
        {
            request.setAttribute("password","密码格式错误");
            request.getRequestDispatcher("Register.jsp").forward(request,response);
        }
        if(userName.length()<1||userName.length()>32)
        {
            request.setAttribute("name","昵称格式错误");
            request.getRequestDispatcher("Register.jsp").forward(request,response);
            return;
        }
        if(!isPhoneRight(usePhone))
        {
            request.setAttribute("phone","手机格式错误");
            request.getRequestDispatcher("Register.jsp").forward(request,response);
            return;
        }
        if(!isUserIdNumberRight(userIdNumber))
        {
            request.setAttribute("idNumber","身份证格式错误");
            request.getRequestDispatcher("Register.jsp").forward(request,response);
            return;
        }
        UserDao u=new UserDaoImpl();
        if(u.findAccount(userAccount))
        {
            request.setAttribute("account","该账户已存在");
            request.getRequestDispatcher("Register.jsp").forward(request,response);
            return;
        }
        User user =new User();
        user.setIdentity("普通用户");
        user.setUserIdNumber(userIdNumber);
        user.setUserPhone(usePhone);
        user.setUserAccount(userAccount);
        user.setUserPassword(usePassword);
        user.setUserName(userName);
        request.getSession().setAttribute("user",user);
        if(u.register(userName,usePassword,usePhone,userAccount,userIdNumber))
            response.sendRedirect("http://localhost:8080/hotel_war_exploded/RegisterSuccess.jsp");

    }

    public  void Update(User user,HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(!isRight(user.getUserPassword()))
        {
            request.setAttribute("userpassword","密码格式错误");
            request.getRequestDispatcher("UpdateSelf.jsp").forward(request,response);
        }
        if(user.getUserName().length()<1||user.getUserName().length()>32)
        {
            request.setAttribute("username","昵称格式错误");
            request.getRequestDispatcher("UpdateSelf.jsp").forward(request,response);
            return;
        }
        if(!isPhoneRight(user.getUserPhone()))
        {
            request.setAttribute("userphone","手机号码格式错误");
            request.getRequestDispatcher("UpdateSelf.jsp").forward(request,response);
            return;
        }
        if(!isUserIdNumberRight(user.getUserIdNumber()))
        {
            request.setAttribute("useridNumber","身份证格式错误");
            request.getRequestDispatcher("UpdateSelf.jsp").forward(request,response);
            return;
        }
        UserDao u=new UserDaoImpl();
            if(u.update(user))
            {
                request.getSession().setAttribute("user",user);
                request.getRequestDispatcher("UpdateSelfSuccess.jsp").forward(request,response);
            }
            else
            {

            }
    }

}