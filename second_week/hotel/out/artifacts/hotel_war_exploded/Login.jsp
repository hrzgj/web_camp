<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/6
  Time: 8:21
  To change this template use File | Settings | File Templates.
--%>
<!-- 登录界面 -->
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>酒店管理系统</title>
</head>

<body style="background:url(image/timg.jpg) ; ">
<div style="display:block;text-align:center;margin: 202px;">
    <table align="center">
        <h1 style="color: red;">用户登录</h1>
        <h4 style="color: red;">
            账号: 6-20位的数字英文组合<br> 密码：6-20位的数字英文组合
        </h4>
        <form  action="LoginServlet" method="post">
            <p>
                <span style="color: green">账号：</span> <input type="text" name="user_account"></input>
            </p>
            <p>
                <span style="color: green">密码：</span> <input type="password" name="user_password"></input>
            </p>
            <p>
                <button class="button2" type="submit">点击登陆</button>
            </p>
        </form>
    </table>
    <table align="center">
        <tr>
            <a href="Register.jsp">注册账户</a>
        </tr>
    </table>
</div>
</body>
</html>

