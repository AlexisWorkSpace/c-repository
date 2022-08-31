mport smtplib
from email.message import EmailMessage

email_subject = "Email test from Python"
sender_email_address = "your_email@gmail.com"
receiver_email_address = "receiver_email@address.com"
email_smtp = "smtp.gmail.com"
email_password = "your_email_password"

# Create an email message object 
message = EmailMessage()

# Configure email headers 
message['Subject'] = email_subject
message['From'] = sender_email_address
message['To'] = receiver_email_address

# Set email body text 
message.set_content("Hello from Python!")

# Set smtp server and port 
server = smtplib.SMTP(email_smtp, '587')

# Identify this client to the SMTP server 
server.ehlo()

# Secure the SMTP connection 
server.starttls()

# Login to email account 
server.login(sender_email_address, email_password)

# Send email 
server.send_message(message)

# Close connection to server 
server.quit()
