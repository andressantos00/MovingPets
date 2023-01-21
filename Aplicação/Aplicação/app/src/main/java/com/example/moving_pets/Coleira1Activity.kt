package com.example.moving_pets

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.ImageButton
import android.widget.TextView
import com.google.android.material.datepicker.MaterialPickerOnPositiveButtonClickListener


class Coleira1Activity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_coleira1)

        findViewById<Button>(R.id.button).setOnClickListener {

            val intent = Intent(this, Coleira1NomeActivity::class.java)
            val st = findViewById<EditText>(R.id.editTextTextPersonName2).text.toString()
            intent.putExtra("Value", st)
            startActivity(intent)
        }


    }
}