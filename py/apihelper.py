def info (object, spacing=10, collapse=1):
    """print methods and doc strings

    Takes module, class, list, dictionary or string."""
    
    methodList = [m for m in dir(object) if callable (getattr(object, m))]
    
    processFunc = collapse and (lambda s: " ".join (s.split())) or (lambda s: s)
    
    print '\n'.join(["%s %s" %
                     (m.ljust(spacing),
                     processFunc (str (getattr (object, m).__doc__)))
                    for m in methodList])


if __name__ == "__main__":
    print info.__doc__


