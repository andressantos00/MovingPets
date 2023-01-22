package com.example.moving_pets

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageButton


class selecao_coleiras : AppCompatActivity()
{
    override fun onCreate(savedInstanceState: Bundle?)
    {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.selecao_coleiras)

        findViewById<ImageButton>(R.id.imageButton2).setOnClickListener {

            val intent = Intent(this, tabela_dados::class.java)
            startActivity(intent)
        }


    }
}