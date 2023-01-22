package com.example.moving_pets

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageButton


class selecao_concentradores : AppCompatActivity()
{
    override fun onCreate(savedInstanceState: Bundle?)
    {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.selecao_concentradores)

        findViewById<ImageButton>(R.id.Concentrador1_Button).setOnClickListener{
                val intent = Intent(this, selecao_coleiras::class.java)
                startActivity(intent)
        }

    }
}