import os
from twilio.rest import Client

account_sid = 'AC630da0d5ae6b0071f89db5707d5191f1'
auth_token = '09107c328a3f4c81c7d00694a4fcba3c'
client = Client(account_sid, auth_token)

contact_list = {'c1':"+919790590251", "c2":"+919113576219","c3":"+918277099592"}

def call(number, msg):
    call = client.calls.create(
                            twiml='<Response><Say>'+msg+'</Say></Response>',
                            to=number ,
                from_= '+18706148173'
                        )

def sms(number, msg):
	client = Client(account_sid, auth_token)
	client.messages.create(from_= '+18706148173',
                       	to= number,
                       	body= msg)


def emergency():
	call(contact_list['c3'], "Emergency")

def msg(message):
	sms(contact_list['c3'], message)

		

