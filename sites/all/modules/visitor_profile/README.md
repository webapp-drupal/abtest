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

**Profile** creation on poll  - major task not done
**On time of creating Profile for the visitor:**

1. Fetch Host ip - **DONE**
2. Record the ip in cookie if the ip dinamic (not the same ) we are checking the cookies in the browser are set or not  if YES -> get the cookies ip    value if NOT - > record it in cookies and create profile - **DONE**
3. Detect Geolocation - almost done
4. Record personal question in profile - preprocess function has errors almost done

**Profile display**
1. Queries to display profile on page - not done
2. Theme for the profile page - not done
3. Append records for the profile each time poll voted or pages visited - not done
4. Extract - tags from visited pages and save to the profile - not done










