package com.example.moving_pets

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageButton


class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        findViewById<ImageButton>(R.id.Concentrador1_Button).setOnClickListener{


                val intent = Intent(this, Coleira1Activity::class.java)
                startActivity(intent)
        }

        findViewById<ImageButton>(R.id.Concentrador2_Button).setOnClickListener{


            val intent = Intent(this, Coleira2Activity::class.java)
            startActivity(intent)
        }

    }
}