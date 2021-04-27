$top = nil

def push(val)
  elem = {}
  elem[:val] = val
  elem[:next] = nil
  if $top
    elem[:prev] = $top
    $top[:next] = elem
  else
    elem[:prev] = nil
  end
  $top = elem
end

def pop()
  elem = $top
  if elem
    $top = elem[:prev]
    if $top
      $top[:next] = nil
    end

    return elem[:val]
  end
  return nil
end