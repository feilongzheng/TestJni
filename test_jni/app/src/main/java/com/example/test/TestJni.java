package com.example.test;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class TestJni extends Activity{
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		setContentView(R.layout.test_jni);
        TextView tv = (TextView) findViewById(R.id.tv);
        tv.setText(printJNI("55"));
    }
	
	static{
		//加载库文件
		System.loadLibrary("JniTest");
		
	}
	//声明原生函数参数为String类型 返回类型为String
	private native String printJNI(String inputStr); 
	
	

}
