package com.example.moving_pets

import android.os.Bundle
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import com.google.firebase.database.DatabaseError
import org.w3c.dom.Text


class tabela_dados : AppCompatActivity()
{

    override fun onCreate(savedInstanceState: Bundle?)
    {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.tabela_dados_firebase)

        var database = FirebaseDatabase.getInstance()
        val myRef = database.getReference("Coleiras/Device_1")

        myRef.addValueEventListener(object : ValueEventListener
        {
            override fun onDataChange(dataSnapshot: DataSnapshot)
            {
                if (dataSnapshot.exists())
                {
                    val Data_Hora = arrayOfNulls<String>(10)
                    for (i in 0 until 10)
                    {
                        val value = dataSnapshot.child(i.toString()+"Data&Hora").value.toString()
                        Data_Hora[i] = value
                    }

                    val BatimentosCardiacos = arrayOfNulls<String>(10)
                    for (i in 0 until 10)
                    {
                        val value = dataSnapshot.child(i.toString()+"BatimentosCardiacos").value.toString()
                        BatimentosCardiacos[i] = value
                    }

                    val NiveisOxigenio = arrayOfNulls<String>(10)
                    for (i in 0 until 10)
                    {
                        val value = dataSnapshot.child(i.toString()+"NiveisOxigenio").value.toString()
                        NiveisOxigenio[i] = value
                    }

                    val Aceleracao = arrayOfNulls<String>(10)
                    for (i in 0 until 10)
                    {
                        val value = dataSnapshot.child(i.toString()+"Aceleracao").value.toString()
                        Aceleracao[i] = value
                    }

                    val Temperatura = arrayOfNulls<String>(10)
                    for (i in 0 until 10)
                    {
                        val value = dataSnapshot.child(i.toString()+"Temperatura").value.toString()
                        Temperatura[i] = value
                    }

                    val BatteryVoltage = arrayOfNulls<String>(10)
                    for (i in 0 until 10)
                    {
                        val value = dataSnapshot.child(i.toString()+"BatteryVoltage").value.toString()
                        BatteryVoltage[i] = value
                    }


                    /*val Data_Hora = dataSnapshot.child("Data&Hora").value
                    val BatimentosCardiacos = dataSnapshot.child("BatimentosCardiacos").value
                    val NiveisOxigenio = dataSnapshot.child("NiveisOxigenio").value
                    val Aceleracao = dataSnapshot.child("Aceleracao").value
                    val Temperatura = dataSnapshot.child("Temperatura").value
                    val BatteryVoltage = dataSnapshot.child("BatteryVoltage").value*/

                    /*val Table_x1 = arrayOfNulls<TextView>(9)
                    val id_Table_x1 = arrayOf(R.id.Table_11, R.id.Table_21, R.id.Table_31, R.id.Table_41,R.id.Table_51,R.id.Table_61,R.id.Table_71,R.id.Table_81,R.id.Table_91)
                    for (i in id_Table_x1)
                    {
                        val view = findViewById<TextView>(i)
                        Table_x1[i] = view
                    }
                    for (i in 0 until 9)
                    {
                        Table_x1[i]?.setText(Data_Hora[i])
                    }*/

                    val Table_11 = findViewById<TextView>(R.id.Table_11)
                    Table_11.setText(Data_Hora[1])
                    val Table_21 = findViewById<TextView>(R.id.Table_21)
                    Table_21.setText(Data_Hora[2])
                    val Table_31 = findViewById<TextView>(R.id.Table_31)
                    Table_31.setText(Data_Hora[3])
                    val Table_41 = findViewById<TextView>(R.id.Table_41)
                    Table_41.setText(Data_Hora[4])
                    val Table_51 = findViewById<TextView>(R.id.Table_51)
                    Table_51.setText(Data_Hora[5])
                    val Table_61 = findViewById<TextView>(R.id.Table_61)
                    Table_61.setText(Data_Hora[6])
                    val Table_71 = findViewById<TextView>(R.id.Table_71)
                    Table_71.setText(Data_Hora[7])
                    val Table_81 = findViewById<TextView>(R.id.Table_81)
                    Table_81.setText(Data_Hora[8])
                    val Table_91 = findViewById<TextView>(R.id.Table_91)
                    Table_91.setText(Data_Hora[9])

                    val Table_12 = findViewById<TextView>(R.id.Table_12)
                    Table_12.setText(BatimentosCardiacos[1])
                    val Table_22 = findViewById<TextView>(R.id.Table_22)
                    Table_22.setText(BatimentosCardiacos[2])
                    val Table_32 = findViewById<TextView>(R.id.Table_32)
                    Table_32.setText(BatimentosCardiacos[3])
                    val Table_42 = findViewById<TextView>(R.id.Table_42)
                    Table_42.setText(BatimentosCardiacos[4])
                    val Table_52 = findViewById<TextView>(R.id.Table_52)
                    Table_52.setText(BatimentosCardiacos[5])
                    val Table_62 = findViewById<TextView>(R.id.Table_62)
                    Table_62.setText(BatimentosCardiacos[6])
                    val Table_72 = findViewById<TextView>(R.id.Table_72)
                    Table_72.setText(BatimentosCardiacos[7])
                    val Table_82 = findViewById<TextView>(R.id.Table_82)
                    Table_82.setText(BatimentosCardiacos[8])
                    val Table_92 = findViewById<TextView>(R.id.Table_92)
                    Table_92.setText(BatimentosCardiacos[9])

                    val Table_13 = findViewById<TextView>(R.id.Table_13)
                    Table_13.setText(NiveisOxigenio[1])
                    val Table_23 = findViewById<TextView>(R.id.Table_23)
                    Table_23.setText(NiveisOxigenio[2])
                    val Table_33 = findViewById<TextView>(R.id.Table_33)
                    Table_33.setText(NiveisOxigenio[3])
                    val Table_43 = findViewById<TextView>(R.id.Table_43)
                    Table_43.setText(NiveisOxigenio[4])
                    val Table_53 = findViewById<TextView>(R.id.Table_53)
                    Table_53.setText(NiveisOxigenio[5])
                    val Table_63 = findViewById<TextView>(R.id.Table_63)
                    Table_63.setText(NiveisOxigenio[6])
                    val Table_73 = findViewById<TextView>(R.id.Table_73)
                    Table_73.setText(NiveisOxigenio[7])
                    val Table_83 = findViewById<TextView>(R.id.Table_83)
                    Table_83.setText(NiveisOxigenio[8])
                    val Table_93 = findViewById<TextView>(R.id.Table_93)
                    Table_93.setText(NiveisOxigenio[9])

                    val Table_14 = findViewById<TextView>(R.id.Table_14)
                    Table_14.setText(Aceleracao[1])
                    val Table_24 = findViewById<TextView>(R.id.Table_24)
                    Table_24.setText(Aceleracao[2])
                    val Table_34 = findViewById<TextView>(R.id.Table_34)
                    Table_34.setText(Aceleracao[3])
                    val Table_44 = findViewById<TextView>(R.id.Table_44)
                    Table_44.setText(Aceleracao[4])
                    val Table_54 = findViewById<TextView>(R.id.Table_54)
                    Table_54.setText(Aceleracao[5])
                    val Table_64 = findViewById<TextView>(R.id.Table_64)
                    Table_64.setText(Aceleracao[6])
                    val Table_74 = findViewById<TextView>(R.id.Table_74)
                    Table_74.setText(Aceleracao[7])
                    val Table_84 = findViewById<TextView>(R.id.Table_84)
                    Table_84.setText(Aceleracao[8])
                    val Table_94 = findViewById<TextView>(R.id.Table_94)
                    Table_94.setText(Aceleracao[9])

                    val Table_15 = findViewById<TextView>(R.id.Table_15)
                    Table_15.setText(Temperatura[1])
                    val Table_25 = findViewById<TextView>(R.id.Table_25)
                    Table_25.setText(Temperatura[2])
                    val Table_35 = findViewById<TextView>(R.id.Table_35)
                    Table_35.setText(Temperatura[3])
                    val Table_45 = findViewById<TextView>(R.id.Table_45)
                    Table_45.setText(Temperatura[4])
                    val Table_55 = findViewById<TextView>(R.id.Table_55)
                    Table_55.setText(Temperatura[5])
                    val Table_65 = findViewById<TextView>(R.id.Table_65)
                    Table_65.setText(Temperatura[6])
                    val Table_75 = findViewById<TextView>(R.id.Table_75)
                    Table_75.setText(Temperatura[7])
                    val Table_85 = findViewById<TextView>(R.id.Table_85)
                    Table_85.setText(Temperatura[8])
                    val Table_95 = findViewById<TextView>(R.id.Table_95)
                    Table_95.setText(Temperatura[9])

                    val Table_16 = findViewById<TextView>(R.id.Table_16)
                    Table_16.setText(BatteryVoltage[1])
                    val Table_26 = findViewById<TextView>(R.id.Table_26)
                    Table_26.setText(BatteryVoltage[2])
                    val Table_36 = findViewById<TextView>(R.id.Table_36)
                    Table_36.setText(BatteryVoltage[3])
                    val Table_46 = findViewById<TextView>(R.id.Table_46)
                    Table_46.setText(BatteryVoltage[4])
                    val Table_56 = findViewById<TextView>(R.id.Table_56)
                    Table_56.setText(BatteryVoltage[5])
                    val Table_66 = findViewById<TextView>(R.id.Table_66)
                    Table_66.setText(BatteryVoltage[6])
                    val Table_76 = findViewById<TextView>(R.id.Table_76)
                    Table_76.setText(BatteryVoltage[7])
                    val Table_86 = findViewById<TextView>(R.id.Table_86)
                    Table_86.setText(BatteryVoltage[8])
                    val Table_96 = findViewById<TextView>(R.id.Table_96)
                    Table_96.setText(BatteryVoltage[9])

                }
            }
            override fun onCancelled(error: DatabaseError) {}

        })
    }
}


