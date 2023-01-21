package com.example.moving_pets

import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.moving_pets.databinding.ActivityColeira1NomeBinding
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase

class Coleira1NomeActivity : AppCompatActivity() {

    private lateinit var binding: ActivityColeira1NomeBinding
    private lateinit var database : DatabaseReference


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityColeira1NomeBinding.inflate(layoutInflater)

        setContentView(binding.root)

        val tv = findViewById<TextView>(R.id.etusername)

        val st = intent.extras?.getString("Value")
        tv.setText(st)

        binding.readdataBtn.setOnClickListener {

            val userName : String = binding.etusername.text.toString()
            if  (userName.isNotEmpty()){

                readData(userName)

            }else{

                Toast.makeText(this,"Por favor introduza o nome do animal",Toast.LENGTH_SHORT).show()

            }

        }

    }

    private fun readData(userName: String) {

        database = FirebaseDatabase.getInstance().getReference("Sensor")
        database.child(userName).get().addOnSuccessListener {

            if (it.exists()){

                val HeartRate = it.child("HeartRate").value
                val OxygenLevels = it.child("OxygenLevels").value
                val Temperature = it.child("Temperature").value
                val Acceleration = it.child("Acceleration").value
                val BatteryVoltage = it.child("BatteryVoltage").value
                val Device = it.child("Device").value
                Toast.makeText(this,"Successfuly Read",Toast.LENGTH_SHORT).show()
                //binding.etusername.text
                binding.tvHeartRate.text = HeartRate.toString()
                binding.tvOxygenLevels.text = OxygenLevels.toString()
                binding.tvTemperature.text = Temperature.toString()
                binding.tvAcceleration.text = Acceleration.toString()
                binding.tvBatteryVoltage.text = BatteryVoltage.toString()
                binding.tvDevice.text = Device.toString()

            }else{

                Toast.makeText(this,"O animal não existe",Toast.LENGTH_SHORT).show()


            }

        }.addOnFailureListener{

            Toast.makeText(this,"Failed", Toast.LENGTH_SHORT).show()


        }



    }
}


