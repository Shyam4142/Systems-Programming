# Shyam Venkatesan
# Exercise 2

#!/usr/bin/perl

# Arrays for username and score information
@usernames = ("Sarah1", "Sarah2", "sarah3", "sArah4");
@scores = (10, 7, 42, 3);

# Arrays are combined into a hash, participants
%participants;
@participants{@usernames} = @scores;

# A: ASCII-betical by participant username
print "ASCII-betical by Participant Username:\n"; 
foreach $username (sort keys %participants) # Iterates through participants
{
    print "$username - $participants{$username}\n"; # Prints their name and score
}

# B: case-insensitive ASCII-betical by participant username
print "\nCase-insensitive ASCII-betical by Participant Username:\n";
foreach $username (sort {lc($a) cmp lc($b)} keys %participants)  # Sorts participants based on a lower case comparison, then iterates
{
    print "$username - $participants{$username}\n"; # Prints their name and score
}

# C: numerical order by participant score (lowest to highest)
print "\nNumerical Order by Participant Score (lowest to highest):\n";
foreach my $username (sort {$participants{$a} <=> $participants{$b}} keys %participants)  # Sorts participants based on their score in an ascending order, then iterates
{
    print "$username - $participants{$username}\n"; # Prints their name and score
}

# D: reverse numerical order by participant score (highest to lowest)
print "\nReverse Numerical Order by Participant Score (highest to lowest):\n"; # Sorts participants based on their score in an descending order, then iterates
foreach $username (sort {$participants{$b} <=> $participants{$a}} keys %participants) 
{
    print "$username - $participants{$username}\n"; # Prints their name and score
}



