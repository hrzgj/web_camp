package com.chenyu.www.util;

import java.sql.*;

public class DaoUtil {
    private static final String url = "jdbc:mysql://localhost:3306/hotel?useUnicode=true&characterEncoding=UTF-8";
    private static final String username = "root";
    private static final String password = "2289360";
    private static final String jdbcName = "com.mysql.jdbc.Driver";

    public Connection getCon() {
        try {
            Class.forName(jdbcName);

        } catch (ClassNotFoundException e) {
            System.out.println("加载数据库连接失败");
            e.printStackTrace();
        }
        Connection con = null;
        try {
            con = DriverManager.getConnection(url, username, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return con;
    }

    public void close(PreparedStatement pstmt, Connection conn) {
        if (pstmt != null) {
            try {
                pstmt.close();
            } catch (SQLException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

    }
}
