# Module objectives 
**Name: Visitor Profile**
Create profile for the anonimous visitor when poll voited. Collect all votes and page visits on profile. Collect geo location via GEOIP2. Collect personal information and store it in proifile


# Requirements

GeoIP2 Library and account is for to track visitor location by ip

# Custom Entityies:

**Profile**
properties :  id host time_created  
fields : geo_location, tags(from url's visited), personal_info_fields multivalued fieldset (fetched from polls)

**Visits**
properties : id profile_id time_visited url_visited

**Extending Polls functionality**
Alter the form for the creation off polls. Extend poll node by checkbox whether question is for anonimous visitor profile 
on check box open field to fill the personal question add form to submit habdler to collect personal questions answer
save the answer in profile. Save poll answer to the  profile


On time of voiting:

1. Add form to collect personal answer after voitig - check if personal question is added show form to collect the answer and point 3 if no do only 2 point
2. Create record for the anonimous visitor - check record for the host already exists store the vote choice  
3. Add personal question to the Proifile

    
On time of creating Profile for the visitor:

Fetch Host ip
Detect Geolocation
Record personal question in profile

