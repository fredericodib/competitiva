def can_select(arr, elem)
    arr.each do |e|
        if (elem[0] >= e[0] && elem[0] <= e[1]) || (elem[1] >= e[0] && elem[1] <= e[1]) || (elem[0] <= e[0] && elem[1] >= e[1])
            return false
        end
    end
    return true
end

n = gets().to_i

ent = []

for i in 1..n
    ent << gets().split(' ').map {|e| e.to_i}
end

ent = ent.sort_by { |a| [a[1]-a[0],a[0]] }

ent = ent.uniq { |s| s[0] }
ent = ent.uniq { |s| s[1] }


path = []
size = 0

ent.each do |e|
    if can_select(path, e)
        path << e
        size += 1
    end
end

puts size