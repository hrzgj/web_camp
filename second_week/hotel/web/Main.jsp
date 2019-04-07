<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/6
  Time: 18:26
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>酒店主界面</title>
</head>
<body style="background:url(image/timg.jpg) ; ">
<div class="main">

    <div class="main_left">
        <div class="li_title">用户管理<span class="down"></span></div>
        <ul>
            <li></li><tr><a href="Print.jsp">查看所有用户信息</a></tr>
            <li></li><tr><a href="Update.jsp">修改其它用户信息</a> </tr>
            <li data-src="userVip.action">改变用户权限</li>
        </ul>

</div>
</div>
</body>
</html>
