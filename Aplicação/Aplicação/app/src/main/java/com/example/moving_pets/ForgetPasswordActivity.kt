package com.example.moving_pets

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class ForgetPasswordActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_forget_password)

        setup()
    }

    private fun setup() {

        findViewById<TextView>(R.id.textView5).setOnClickListener {


            val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)
            finish()
        }
    }

}



