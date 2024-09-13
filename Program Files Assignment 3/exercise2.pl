# Shyam Venkatesan
# Exercise 2

#!/usr/bin/perl

# Participant information arrays (firstnames, lastnames, ages, nativelanguages, performancescores)
@firstnames = ("Sarah", "Jareth", "Ludo", "Hoggle");
@lastnames = ("Williams", "King", "Beast", "Dwarf");
@ages = (15, 39, 33, 43);
@nativelanguages = ("English", "English", "Romanian", "English");
@performancescores = (85, 99, 35, 75);

# Creates an empty hash to store participant information
%participants;

# Iterates through firstnames as the hash key and gives the hash index lastname, age, nativelanguage, and performancescore values
for $i (0 .. $#firstnames) 
{
    $participants{$firstnames[$i]} = 
    {
        lastname => $lastnames[$i],
        age => $ages[$i],
        nativelanguage => $nativelanguages[$i],
        performancescore => $performancescores[$i]
    };
}

# Iterates through the values in the participants hash table and adds each performancescore to totalscore
$totalscore = 0;
foreach $participant (values %participants) 
{
    $totalscore += $participant->{performancescore};
}
$avgscore = $totalscore / (keys %participants); # Divides the total score by number of keys to get the average score

# Print average performance score
print "Average Performance Score: $avgscore";

# A: Native Language is English
print "\n\nNative Language is English:\n";
foreach $name (keys %participants)  # Iterates through name keys of the participants hash
{
    if ($participants{$name}->{nativelanguage} eq "English") # Checks if the the participant keyed with name has a native language equal to English
    {
        print "$name $participants{$name}->{lastname}\n";
    }
}

# B: Age is Greater than 20
print "\nAge is Greater than 20:\n";
foreach $name (keys %participants) # Iterates through name keys of the participants hash
{
    if ($participants{$name}->{age} > 20) # Checks if the the participant keyed with name has age greater than 20
    {
        print "$name $participants{$name}->{lastname}\n"; # Prints the full name
    }
}

# C: Age is Greater than 20 and Native Language is English
print "\nAge is Greater than 20 and Native Language is English:\n";
foreach $name (keys %participants) # Iterates through name keys of the participants hash
{
    if ($participants{$name}->{age} > 20 && $participants{$name}->{nativelanguage} eq "English")  # Checks if the previous 2 statements were true (and)
    {
        print "$name $participants{$name}->{lastname}\n"; # Prints the full name
    }
}

# D: Performance Score is Greater than 7
print "\nPerformance Score is Greater than 70:\n";
foreach $name (keys %participants) # Iterates through name keys of the participants hash
{
    if ($participants{$name}->{performancescore} > 70) # Checks if the the participant keyed with name has a performance score greater than 70
    {
        print "$name $participants{$name}->{lastname}\n"; # Prints the full name
    }
}

