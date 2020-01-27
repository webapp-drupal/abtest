# Module objectives 
**Name: Visitor Profile**
Create profile for the anonimous visitor when poll voited. Collect all votes and page visits on profile. Collect geo location via GEOIP2. Collect personal information and store it in proifile


# Requirements

Poll (core module)
GeoIP Api module
Libraries module
Graph and Charts module
D3 module
Views Decorator module
Decorator module


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

1. Add form to collect personal answer after voitig - check if personal question is added show form to collect the answer and point 3 if NO -> DO only 2 point
2. Create record for the anonimous visitor - check record for the host already exists store the vote choice  
3. Add personal question to the **Proifile**

    

# TO DO #

**Profile** creation on poll  - **DONE**
**On time of creating Profile for the visitor:**

1. Fetch Host ip - **DONE**
2. Record the ip in cookie if the ip dinamic (not the same ) we are checking the cookies in the browser are set or not  if YES -> get the cookies ip    value if NOT - > record it in cookies and create profile - **DONE**
3. Detect Geolocation - **DONE** NOTE: accuracy of the detection on free library is not to good
4. Record personal question in profile - Preprocess function fixed and ready to perform answer collection but only once for the host - almost done

**Profiles admin page display**
1. Views to display profiles in rows and detailed information on single profile with the connections to all information


**Ongoing task to poll voites**
 Possible solution to authenticate each individual voter, so that each user can only vote once.
 2 difficult parts left - identify user is came back via cookies is not a problem. how to identify visitors from one ip (offices for example) of the and let them vote once - this is a problem










