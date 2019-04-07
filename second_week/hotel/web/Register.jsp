<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/6
  Time: 17:11
  To change this template use File | Settings | File Templates.
--%>
<!-- 注册界面 -->
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册用户界面</title>
</head>
<body style="background:url(image/timg.jpg);">
<div style="display:block;text-align:center;margin: 202px;">
    <table align="center">
        <h1 style="color: red;">用户注册</h1>
            <form  action="RegisterServlet" method="post">
                 <p>
                    <span style="color: green">账号：</span> <input type="text" name="user_account">
                     <font color="red">
                         ${requestScope.account}</font>
                 </input>
                <h5 style="color: red;">
                    账号: 6-20位的数字英文组合
                </h5>
                 </p>
                 <p>
                    <span style="color: green">密码：</span> <input type="password" name="user_password">
                     <font color="red">
                         ${requestScope.password}</font>
                 </p>
                <h5 style="color: red;">
                    密码: 6-20位的数字英文组合
                </h5>
                 </p>
                <p>
                    <span style="color: green">昵称：</span> <input type="text" name="user_name">
                    <font color="red">
                        ${requestScope.name}</font>
                </input>
                <h5 style="color: red;">
                    昵称：32位内的字符
                </h5>
                </p>
                <p>
                    <span style="color: green;margin: 0pc;">手机号:</span> <input type="text" name="user_phone">
                    <font color="red">
                        ${requestScope.phone}</font>
                </input>
                <h5 style="color: red;">
                    手机号为11个数字
                </h5>
                </p>
                <p>
                    <span style="color: green;margin: 0pc;">身份证:</span> <input type="text" name="user_idNumber">
                    <font color="red">
                        ${requestScope.idNumber}</font>
                    </input>
                <h5 style="color: red;">
                    身份证为18位数字
                </h5>
                </p>

                 <p>
                     <button class="button2" type="submit">点击注册</button>
                 </p>
            </form>
    </table>
</div>
</body>
</html>
